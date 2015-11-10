#include "triangle.h"

Triangle::Triangle()
{
}
Triangle::Triangle(int, int, int, int)
{
     id_Triangle=-1;
     id_Sommet1=-1;
     id_Sommet2=-1;
     id_Sommet3=-1;

}
Triangle::Triangle(Triangle const& tr)
{
    id_Triangle=tr.id_Triangle;
    id_Sommet1 = tr.id_Sommet1;
    id_Sommet2 = tr.id_Sommet2;
    id_Sommet3 = tr.id_Sommet3;
    z_moy=tr.z_moy;
}

