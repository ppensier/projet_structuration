#ifndef MNT_H
#define MNT_H
#define TAILLE_MAX 1024
#include "Point.h"
#include "triangle.h"
#include<iostream>
#include <vector>

class Mnt
{
public:
    Mnt();
    void loadMnt(std::string fileName);
    std::vector<Point> lesPoints ;
    std::vector<Triangle> lesTriangles ;


};

#endif // MNT_H
