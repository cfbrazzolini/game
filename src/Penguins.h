#ifndef PENGUINS_H
#define PENGUINS_H

#include "Bullet.h"
#include "Camera.h"
#include "CustomMath.h"
#include "GameBase.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Point.h"
#include "Sprite.h"

#define ACCELARATION 100
#define COOLDOWN 1
#define	LOWER_SPEED_LIMIT -500
#define PENGUINS_BULLET_FRAME_COUNT 4
#define PENGUINS_BULLET_FRAME_TIME 0.2
#define PENGUINS_BULLET_RANGE 500
#define PENGUINS_BULLET_SPEED 100
#define ROTATION_ANGLE 5
#define UPPER_SPEED_LIMIT 500


class Penguins : public GameObject
{
public:
    Penguins(float,float);
    ~Penguins();
    void update(float);
    void render();
    bool isDead();
    void shoot();

    static Penguins* player;
private:
	Sprite bodySp;
	Sprite cannonSp;
	Point speed;
	float linearSpeed;
	float cannonAngle;
	int hp;
};

#endif // PENGUINS_H
