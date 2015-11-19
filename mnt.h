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

    /*******/
    std::vector<Point> lesPoints ;
    std::vector<Triangle> lesTriangles ;
    qglviewer::Vec MIN_MNT;
    qglviewer::Vec MAX_MNT;
    float pasX;
    float pasY;


    int nC;
    int nL;
    bool isDisplayed=false;
    float z_max_ses_triangles;
    float z_min_ses_triangles;



};

#endif // MNT_H
