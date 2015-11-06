#ifndef GPX_H
#define GPX_H

#include <vector>
#include "Point.h"
#include <string>
#include "mnt.h"


using namespace std;

class gpx
{
public:
    gpx();
    void openGpx();

    std::vector<Point> ptsGpx;

    Triangle troisLesPlusProches(Mnt& unMnt, Point p);
    bool estDansTriangle(Point p, Mnt& unMnt, int i);
    bool conditionDansTrianglePair(Point p, Mnt& mnt, int i);
    bool conditionDansTriangleImpair(Point p, Mnt& mnt, int i);
private:
    float minlat;
    float maxlat;
    float minlon;
    float maxlon;
};

#endif // GPX_H
