#ifndef POINT_H
#define POINT_H



class Point
{
public:
  //Constructors
    Point();//Par defaut (normalement pas utilisé)
    Point(Point const&);//De copie
    Point(float, float, float);//Avec paramètres
    float x;
    float y;
    float z;
  //Getters
    float getX(void) const ;
    float getY(void) const ;
    float getZ(void) const ;
  //Setters
    void setX(float);
    void setY(float);
    void setZ(float);
private:


};

#endif // POINT_H
