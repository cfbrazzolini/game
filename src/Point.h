#ifndef POINT_H
#define POINT_H

#include <cmath>

#define CLOCKWISE 0
#define COUNTER_CLOCKWISE 1

class Point
{
public:
    Point();
    Point(float,float);
    void setX(float);
    void setY(float);
    float getX();
    float getY();
    float computeDistance(Point);
    Point sum(Point);
    Point sub(Point);
    float computeInclination(Point);
    Point vectorXScalar(float);
    Point vectorRotate(float,int);
    float vectorInclination();
    float vectorMagnitude();
    Point vectorNegate();
    Point vectorNormalize();
    Point vectorProjX();
    Point vectorProjY();
private:
	float x;
	float y;
};

#endif // POINT_H
