#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
public:
    Triangle();
    Triangle(Triangle const&);//De copie
    Triangle(int, int, int, int);

    int id_Triangle;
    int id_Sommet1;
    int id_Sommet2;
    int id_Sommet3;
};

#endif // TRIANGLE_H
