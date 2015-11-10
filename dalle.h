#ifndef DALLE_H
#define DALLE_H
#include "Point.h"
#include <vector>
#include "triangle.h"
#include "mnt.h"

class Dalle
{
public:
    Dalle();

    Point debut;
    Point fin;
    int nC_dalle;
    int nL_dalle;
    float z_min;
    float z_max;
    std::vector<int> id_sesPoints;
    std::vector<Triangle> sesTriangles ;


    /******Méthodes*****/
   //
     void BuildTriangles();
     void initialize_altitude(MNT & unMnt);


};

#endif // DALLE_H
