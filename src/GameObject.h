#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Rect.h"

class GameObject
{
public:
    virtual ~GameObject();
    virtual void update(float) = 0;
    virtual void render() = 0;
    virtual bool isDead() = 0;

    Rect box;
    float rotation;
};

#endif // GAMEOBJECT_H
