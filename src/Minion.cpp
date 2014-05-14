#include "Minion.h"

Minion::Minion(GameObject* minionCenter, float angleOffset) : sp("img/minion.png"),center(minionCenter),angle(angleOffset){


	box.setX(center->box.getCenter().getX() + RADIUS*cos(angle) - sp.getWidth()/2);
	box.setY(center->box.getCenter().getY() + RADIUS*sin(angle)  - sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());

}

void Minion::update(float dt){

	angle += ANGULAR_SPEED * dt;

	
	box.setX(center->box.getCenter().getX() + RADIUS*cos(angle) - sp.getWidth()/2);
	box.setY(center->box.getCenter().getY() + RADIUS*sin(angle)  - sp.getHeight()/2);
}

void Minion::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
}

bool Minion::isDead(){
	return false;
}