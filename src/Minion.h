#ifndef MINION_H
#define MINION_H

#include <cmath>

#include "Bullet.h"
#include "Camera.h"
#include "CustomMath.h"
#include "GameObject.h"
#include "Sprite.h"

#define ANGULAR_SPEED M_PI/3
#define RADIUS 150

class Minion : public GameObject
{
public:
    Minion(GameObject*,float = 0);
    void update(float);
    void render();
    bool isDead();
    void shoot(float,float);
private:
	GameObject* center;
	Sprite sp;
	float angle;
};

#endif // MINION_H
