#include "Alien.h"

Alien::Alien(float x,float y,int nMinions) : sp("img/alien.png"){

	int i;
	Point click;

    hp = ALIEN_HP;


	box.setX(x - sp.getWidth()/2);
	box.setY(y - sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());

	/*for(i=0;i<nMinions;i++){
		angle = i*2*PI/nMinions;
		minionArray.emplace_back(this,angle);
	}*/
}

void Alien::update(float dt){

	auto& input = InputManager::getInstance();
	Point pos,click;
	int i;

	if(input.mousePress(RIGHT_MOUSE_BUTTON)){
		click.setX(input.getMouseX() + Camera::pos.getX());
		click.setY(input.getMouseY() + Camera::pos.getY());

		taskQueue.push(click);
	}

	if(!taskQueue.empty()){
		pos = taskQueue.front();
		if(box.getCenter().computeDistance(pos) < 5){
			taskQueue.pop();
		}else{

			speed = pos.sub(box.getCenter());
			speed = speed.vectorNormalize().vectorXScalar(ALIEN_SPEED*dt);

			box.sumPoint(speed);
		}
	}

	/*for(i=0;i<minionArray.size();i++){
		minionArray[i].update();
	}*/

}


void Alien::render(){
	int i;

	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY());
	/*for(i=0;i<minionArray.size();i++){
		minionArray[i].render();
	}*/
}

bool Alien::isDead(){
	return hp <= 0;
}

Alien::~Alien(){
	
}