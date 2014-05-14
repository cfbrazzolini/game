#include "Alien.h"

Alien::Alien(float x,float y,int nMinions) : sp("img/alien.png"){

	int i;
    float angle;
	Point click;

    hp = ALIEN_HP;
    rotation = 0;
    //sp.setScale(0.5);

    box.setX(x - sp.getWidth()/2);
	box.setY(y - sp.getHeight()/2);
	box.setW(sp.getWidth());
	box.setH(sp.getHeight());



	for(i=0;i<nMinions;i++){
		angle = CustomMath::DegToRad(i * 360/nMinions);
		minionArray.emplace_back(this,angle);
	}
}

void Alien::update(float dt){

	auto& input = InputManager::getInstance();
	Point pos,click;
	int i,closest = 0;
    float distance = std::numeric_limits<float>::max();

	rotation -= 3;

	if(input.mousePress(RIGHT_MOUSE_BUTTON)){
		click.setX(input.getMouseX() + Camera::pos.getX());
		click.setY(input.getMouseY() + Camera::pos.getY());

		taskQueue.push(click);
	}

	if(input.mousePress(LEFT_MOUSE_BUTTON)){

        click.setX((float)input.getMouseX() + Camera::pos.getX());
        click.setY((float)input.getMouseY() + Camera::pos.getY());

        
        for(i=0;i<minionArray.size();i++){
            if(distance > minionArray[i].box.getCenter().computeDistance(click)){
                distance = minionArray[i].box.getCenter().computeDistance(click);
                closest = i;
            }
        }

        minionArray[closest].shoot(click.getX(),click.getY());

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

	for(i=0;i<minionArray.size();i++){
        minionArray[i].update(dt);
	}

}


void Alien::render(){
	int i;

	sp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation);
	for(i=0;i<minionArray.size();i++){
		minionArray[i].render();
	}
}

bool Alien::isDead(){
	return hp <= 0;
}

Alien::~Alien(){
	
}
