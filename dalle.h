#ifndef DALLE_H
#define DALLE_H
#include "Point.h"
#include <vector>
#include "triangle.h"

class Dalle
{
public:
    Dalle();

    Point debut;
    Point fin;
    int nC_dalle;
    int nL_dalle;
    std::vector<int> id_sesPoints;
    std::vector<Triangle> sesTriangles ;

    /******Méthodes*****/
   //
     void BuildTriangles();


};

#endif // DALLE_H
