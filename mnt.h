#ifndef MNT_H
#define MNT_H
#define TAILLE_MAX 1024
#include "Point.h"
#include "dalle.h"
#include "triangle.h"
#include<iostream>
#include <vector>
#include <QGLViewer/qglviewer.h>

class Mnt
{
public:
    Mnt();
    void loadMnt(std::string fileName);
    void BuildTriangles();
    void initializBounding();
    void CalculateBoundsDalle(Point minBounds, Point maxBounds); ////initialise dalle.debut par le point de MNT le plus proche à l'extrémité min du GPX
    void CalculateIndicePointsDalle(); ////initialise dalle.debut par le point de MNT le plus proche à l'extrémité min du GPX

    /*******/
    std::vector<Point> lesPoints ;
    std::vector<Triangle> lesTriangles ;
    qglviewer::Vec MIN_MNT;
    qglviewer::Vec MAX_MNT;
    float pasX;
    float pasY;
    int nC;
    int nL;
    Dalle laDalle;


};

#endif // MNT_H
