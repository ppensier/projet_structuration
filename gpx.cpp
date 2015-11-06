#include "gpx.h"
#include <QXmlStreamReader>
#include <QDebug>
#include <QString>
#include <QFile>
#include "help.h"
#include <iostream>
#include <string.h>

using namespace std;

gpx::gpx()
{
    openGpx();
}
void gpx::openGpx(){

    double lat=0;
    double lon = 0;
    double ele = 0;
    QFile file("/home/gtsi/Téléchargements/test.gpx");
    QString name = "";
    vector<Point> kk;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "File open error:" << file.errorString();
    }
    QXmlStreamReader inputStream(&file);
    while (!inputStream.atEnd() && !inputStream.hasError())
    {
        inputStream.readNext();
        name = inputStream.name().toString();
        if (inputStream.isStartElement() && name == "trkpt") {
            lat = inputStream.attributes().value("lat").toFloat();
            lon = inputStream.attributes().value("lon").toFloat();
            while (!(inputStream.isEndElement()) || (name != "trkpt")) {
                inputStream.readNext();
                name = inputStream.name().toString();
                if (inputStream.isStartElement() && name == "ele"){
                    ele = inputStream.readElementText().toFloat();
                    //help::convertCoord(lon, lat);
                    Point p;
                    p.setX(lon);
                    p.setY(lat);
                    p.setZ(ele);
                    kk.push_back(p);
                    ptsGpx.push_back(p);
                    cout<<"un point dans le gpx"<<endl;
                }
            }
        }
        else if (name=="bounds") {
                minlat = inputStream.attributes().value("minlat").toFloat();
                minlon = inputStream.attributes().value("minlon").toFloat();
                maxlat = inputStream.attributes().value("maxlat").toFloat();
                maxlon = inputStream.attributes().value("maxlon").toFloat();
            }
    }
    for(int i=0; i<ptsGpx.size();i++){
        cout<< ptsGpx[i].getX()<< " " << ptsGpx[i].getY()<< " " << ptsGpx[i].getZ()<<endl;
    }
}

Triangle gpx::troisLesPlusProches(Mnt& unMnt, Point p) {
    int i = 0;
    while(!estDansTriangle(p, unMnt, i)) {
        i++;
    }
    cout << unMnt.lesTriangles[i].id_Sommet1 << endl << unMnt.lesTriangles[i].id_Sommet2 << endl << unMnt.lesTriangles[i].id_Sommet3 << endl;
    return unMnt.lesTriangles[i];
}
bool gpx::estDansTriangle(Point p, Mnt& unMnt, int i) {
    if (i%2==0) {
        return conditionDansTrianglePair(p, unMnt, i);
    }
    else {
        return conditionDansTriangleImpair(p, unMnt, i);
    }
}
bool gpx::conditionDansTrianglePair(Point p, Mnt& mnt, int i) {
    Point p2 = mnt.lesPoints[mnt.lesTriangles[i].id_Sommet2 - 1];
    Point p3 = mnt.lesPoints[mnt.lesTriangles[i].id_Sommet3 - 1];
    return (    ( p.getX() > p3.getX() )
             && ( p.getY() < p2.getY() )
             && ( p.getX() < p2.getX() )
             && ( p.getY() > p3.getY() )
             && (mnt.pasX * p.getY() - mnt.pasY * p.getX() > mnt.pasX * p2.getY() - mnt.pasY * p2.getX() ) );
}
bool gpx::conditionDansTriangleImpair(Point p, Mnt& mnt, int i) {
    Point p1 = mnt.lesPoints[mnt.lesTriangles[i].id_Sommet1 - 1];
    Point p2 = mnt.lesPoints[mnt.lesTriangles[i].id_Sommet2 - 1];
    return (    ( p.getX() > p2.getX() )
             && ( p.getY() < p1.getY() )
             && ( p.getX() < p1.getX() )
             && ( p.getY() > p2.getY() )
             && (mnt.pasX * p.getY() - mnt.pasY * p.getX() < mnt.pasX * p2.getY() - mnt.pasY * p2.getX() ) );
}
