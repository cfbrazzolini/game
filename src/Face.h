#ifndef FACE_H
#define FACE_H

#include "Camera.h"
#include "GameObject.h"
#include "Sprite.h"


class Face : public GameObject
{
public:
    Face(float,float);
    void damage(int);
    void update(float);
    void render();
    bool isDead();
private:
	int hitpoints;
	Sprite sp;
};

#endif // FACE_H
