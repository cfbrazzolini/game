#include "CustomMath.h"

CustomMath::CustomMath()
{
}

float CustomMath::DegToRad(float theta) {
    return theta*PI/180;
}

float CustomMath::RadToDeg(float theta) {
    return theta*180/PI;
}
