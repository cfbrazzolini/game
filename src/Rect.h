#ifndef RECT_H
#define RECT_H

#include "Point.h"

class Rect
{
public:
    Rect();
    Rect(float,float,float,float);
    void setX(float);
    void setY(float);
    void setW(float);
    void setH(float);
    float getX();
    float getY();
    float getW();
    float getH();
    Point getCenter();
    void sumPoint(Point);
    float computeDistance(Rect);
    bool hasPoint(Point);
    bool isInside(float,float);
private:
    float x;
    float y;
    float w;
    float h;
};

#endif // RECT_H
