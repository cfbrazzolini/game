#ifndef ALIEN_H
#define ALIEN_H

#include <cmath>
#include <limits>
#include <queue>
#include <vector>

#include "Bullet.h"
#include "Camera.h"
#include "CustomMath.h"
#include "GameBase.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Minion.h"
#include "Point.h"
#include "Sprite.h"
#include "StillAnimation.h"

#define ALIEN_DEATH_ENDS true
#define ALIEN_DEATH_FRAME_COUNT 4
#define ALIEN_DEATH_FRAME_TIME 0.2
#define ALIEN_DEATH_TIME_LIMIT 3
#define ALIEN_HP 50
#define ALIEN_SPEED 100


class Alien : public GameObject
{
public:
	Alien(float,float,int);
	~Alien();
	void update(float);
	void render();
	bool isDead();
	void notifyCollision(GameObject&);
	bool is(const std::string&);
private:
	Sprite sp;
	Point speed;
	int hp;
	std::queue<Point> taskQueue;
	std::vector<Minion> minionArray;
	bool exploded;
};

#endif // ALIEN_H
