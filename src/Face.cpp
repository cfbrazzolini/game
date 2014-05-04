#include "Face.h"

Face::Face(float x,float y) : sp("img/penguinface.png"){

	box.setX(x - sp.getWidth()/2);
	box.setY(y - sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());

	hitpoints = 30;
}

void Face::damage(int damage){
	hitpoints -= damage;
}

void Face::update(float dt){

}

void Face::render(){

    sp.render(box.getX(),box.getY());
}

bool Face::isDead(){
	return hitpoints <= 0;
}
