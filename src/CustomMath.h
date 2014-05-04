#ifndef CUSTOMMATH_H
#define CUSTOMMATH_H

class CustomMath
{
private:
public:
    static constexpr float PI = 3.1415;
    CustomMath();
    static float DegToRad (float);          //converte um valor de graus para raidanos
    static float RadToDeg (float);          //converte um valor de radianos para graus
};

#endif // CUSTOMMATH_H
