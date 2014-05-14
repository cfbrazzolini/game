#ifndef BULLET_H
#define BULLET_H

#include <cmath>
#include <string>

#include "Camera.h"
#include "CustomMath.h"
#include "GameObject.h"
#include "Point.h"
#include "Sprite.h"

class Bullet : public GameObject
{
public:
    Bullet(float,float,float,float,float,const std::string& sprite);
    void update(float);
    void render();
    bool isDead();
private:
	Sprite sp;
	Point speed;
	float distanceLeft;
};

#endif // BULLET_H
