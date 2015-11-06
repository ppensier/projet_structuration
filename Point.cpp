#include "Point.h"

/*-------------------------------------------------------------------------------------------------
 *
 *                                    Les constructeurs
 *
 *-------------------------------------------------------------------------------------------------
*/
Point::Point()
{
    x=-1;
    y=0.0;
    z=0.0;
    id_point = 0;
}
Point::Point(const Point &pt){
    id_point=pt.id_point;
    x = pt.getX();
    y = pt.getY();
    z = pt.getZ();
}
Point::Point(float xx, float yy, float zz){
    x = xx;
    y = yy;
    z = zz;
    id_point = 0;
}
/*-------------------------------------------------------------------------------------------------
 *
 *                                      Les setters
 *
 *-------------------------------------------------------------------------------------------------
*/
void Point::setX(float xx){
    x = xx;
}
void Point::setY(float yy){
    y = yy;
}
void Point::setZ(float zz){
    z = zz;
}
/*-------------------------------------------------------------------------------------------------
 *
 *                                      Les getters
 *
 *-------------------------------------------------------------------------------------------------
*/
float Point::getX(void) const {
    return x;
}
float Point::getY(void) const {
    return y;
}
float Point::getZ(void) const {
    return z;
}
