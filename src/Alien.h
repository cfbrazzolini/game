#ifndef ALIEN_H
#define ALIEN_H

#include <queue>
#include <vector>

#include "Camera.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Minion.h"
#include "Point.h"
#include "Sprite.h"

#define ALIEN_HP 30
#define ALIEN_SPEED 100

class Alien : public GameObject
{
public:
	Alien(float,float,int);
	~Alien();
	void update(float);
	void render();
	bool isDead();
private:
	Sprite sp;
	Point speed;
	int hp;
	std::queue<Point> taskQueue;
	std::vector<Minion> minionArray;
};

#endif // ALIEN_H
