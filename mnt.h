#ifndef MNT_H
#define MNT_H
#define TAILLE_MAX 1024
#include "Point.h"
#include<iostream>
#include <vector>

class Mnt
{
public:
    Mnt();
    Mnt(std::string fileName);
    std::vector<Point> lesPoints ;
};

#endif // MNT_H
