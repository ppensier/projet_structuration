#ifndef POINT_H
#define POINT_H



class Point
{
public:
  //Constructors
    Point();//Par defaut (normalement pas utilisé)
    Point(Point const&);//De copie
    Point(int, int, int);//Avec paramètres
  //Getters
    float getX(void) const ;
    float getY(void) const ;
    float getZ(void) const ;
  //Setters
    void setX(float);
    void setY(float);
    void setZ(float);
private:

    float x;
    float y;
    float z;
};

#endif // POINT_H
