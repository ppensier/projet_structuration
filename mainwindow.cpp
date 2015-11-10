#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <QFileDialog>
#include <QString>
#include <QCheckBox>
#include<QVBoxLayout>
#include <fstream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widgetZoneVisu->leMnt=new Mnt();

    ui->widgetZoneVisu->leMnt->loadMnt("//home//gtsi//DDDgpx//Ecrins2.xyz");

    //4-Retrouver les triangles de dalle à partir des points de la dalle : leMnt->setTriangles();
//bounds de GPX : voir Romain...
    Point BoundsMin;
    BoundsMin.x=ui->widgetZoneVisu->leMnt->MIN_MNT.x;
            //900111;
            //;
            //;0.1
            //980000
    BoundsMin.y=ui->widgetZoneVisu->leMnt->MIN_MNT.y;
            //1900026;
            //;
            //;-0.75
            //1904000
    Point BoundsMax;
    BoundsMax.x= ui->widgetZoneVisu->leMnt->MAX_MNT.x;
            //900511;
            //;
            //;0.9
            //990000
            ////
    BoundsMax.y= ui->widgetZoneVisu->leMnt->MAX_MNT.y;
            //1900126;
            //;
            //;-0.1
            //1940000
            ////
//1-Trouver les deux points délimitant la dalle leMnt-> ; leMnt->CalculateMaxDalle(maxBounds);
//2-Construire la dalle : leMnt->dalle.setBounds(p1,p2);

//ui->widgetZoneVisu->leMnt->CalculateBoundsDalle(BoundsMin,BoundsMax);

//3-Définir les indices du maillage de la dalle : leMnt.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           Dalle();
//ui->widgetZoneVisu->leMnt->CalculateIndicePointsDalle();
//ui->widgetZoneVisu->leMnt->BuildTriangles();
/*=======
   ui->widgetZoneVisu->leMnt->loadMnt("//home//gtsi//Téléchargements//Ecrin.xyz");
    ui->widgetZoneVisu->leGpx=new gpx();
    ui->widgetZoneVisu->leMnt->BuildTriangles();
>>>>>>> 1d4b32e25665a25d03f9641b39f5ceba00554526*/

    //ui->widgetZoneVisu->leGpx->troisLesPlusProches(*ui->widgetZoneVisu->leMnt, ui->widgetZoneVisu->leGpx->ptsGpx[0]);

ui->widgetZoneVisu->leGpx=new gpx();
ui->widgetZoneVisu->leGpx->loadGpx("");
ui->widgetZoneVisu->leGpx->minlat=BoundsMin.y;
ui->widgetZoneVisu->leGpx->minlon=BoundsMin.x;
ui->widgetZoneVisu->leGpx->maxlat=BoundsMax.y;
ui->widgetZoneVisu->leGpx->maxlon=BoundsMax.x;
ui->widgetZoneVisu->leGpx->CalculateBoundsDalle(*(ui->widgetZoneVisu->leMnt));

ui->widgetZoneVisu->leGpx->CalculateIndicePointsDalle(*(ui->widgetZoneVisu->leMnt));

ui->widgetZoneVisu->leGpx->BuildTriangles(*(ui->widgetZoneVisu->leMnt));

}

void MainWindow::on_Action_ouvrirMNT_triggered()
{

/*
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open MNT"), "/home/jana", tr("All files  (*.xyz)"));

    std::cout<<fileName.toStdString();

    cbMNT=new QCheckBox(fileName,this);

    cbMNT->move(10,100);
    cbMNT->show();
    //récupération des coordonnées des points à partir du fichier chargé
    //ui->widgetZoneVisu->loadMnt(fileName.toStdString());
*/
}

MainWindow::~MainWindow()
{
   // delete cbMNT;
    delete ui;

}
