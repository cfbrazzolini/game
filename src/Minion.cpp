#include "Minion.h"

Minion::Minion(GameObject* minionCenter, float angleOffset) : sp("img/minion.png"),center(minionCenter),angle(angleOffset){

	sp.setScale(0.5);
	rotation = -1*(90 - fmod(CustomMath::RadToDeg(angle),90));
	
	box.setX(center->box.getCenter().getX() + RADIUS*cos(angle) - sp.getWidth()/2);
	box.setY(center->box.getCenter().getY() + RADIUS*sin(angle)  - sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());



}

void Minion::update(float dt){

	angle += ANGULAR_SPEED * dt;
	rotation = -1*(90 - fmod(CustomMath::RadToDeg(angle),90));
	
	box.setX(center->box.getCenter().getX() + RADIUS*cos(angle) - sp.getWidth()/2);
	box.setY(center->box.getCenter().getY() + RADIUS*sin(angle)  - sp.getHeight()/2);
}

void Minion::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation);
}

bool Minion::isDead(){
	return false;
}

void Minion::shoot(float x,float y){
	
}