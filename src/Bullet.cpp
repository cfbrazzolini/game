#include "Bullet.h"

Bullet::Bullet(float x,float y,float angle,float speed,float maxDistance,const std::string& sprite) : sp(sprite){

	box.setX(x - sp.getWidth()/2);
    box.setY(y - sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());

    rotation = CustomMath::RadToDeg(angle);
	distanceLeft = maxDistance;

	this->speed.setX(speed * cos(angle));
	this->speed.setY(speed * sin(angle));
}

void Bullet::update(float dt){
	box.sumPoint(speed.vectorXScalar(dt));

    distanceLeft -= speed.vectorXScalar(dt).vectorMagnitude();
}

void Bullet::render(){
	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation);
}

bool Bullet::isDead(){
	return distanceLeft <= 0;
}
