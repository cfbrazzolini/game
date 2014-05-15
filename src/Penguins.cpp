#include "Penguins.h"

Penguins* Penguins::player = nullptr;

Penguins::Penguins(float x, float y) : 	bodySp("img/penguindad.png"),
										cannonSp("img/cubngun.png"),
										linearSpeed(0),
										cannonAngle(0),
										hp(50)
{

	rotation = 0;
	box.setX(x - bodySp.getWidth()/2);
	box.setY(y - bodySp.getHeight()/2);
	box.setW(bodySp.getWidth());
	box.setH(bodySp.getHeight());

	player = this;
}

Penguins::~Penguins(){
	player = nullptr;
}

void Penguins::update(float dt){

	auto& input = InputManager::getInstance();
	Point click;

    click.setX((float)input.getMouseX() + Camera::pos.getX());
    click.setY((float)input.getMouseY() + Camera::pos.getY());

    cannonAngle = box.getCenter().computeInclination(click);

    if(input.mousePress(SDL_BUTTON_LEFT)){
    	shoot();
    }


	if(input.isKeyDown(W_KEY)){
		linearSpeed += ACCELARATION * dt;
	}
	else if(input.isKeyDown(S_KEY)){
		linearSpeed -= ACCELARATION * dt;
	}else{
		linearSpeed = linearSpeed*0.99;
	}


	if(input.isKeyDown(A_KEY)){
		rotation += ROTATION_ANGLE;
	}

	if(input.isKeyDown(D_KEY)){
		rotation -= ROTATION_ANGLE;
	}

	if(input.isKeyDown(Z_KEY)){
       linearSpeed = 0;
    }

    speed.setX(linearSpeed * cos(CustomMath::degToRad(rotation)));
    speed.setY(linearSpeed * sin(CustomMath::degToRad(rotation)));

    box.sumPoint(speed.vectorXScalar(dt));
}

void Penguins::render(){

	bodySp.render(box.getX() - Camera::pos.getX(),box.getY() - Camera::pos.getY(),rotation);
	cannonSp.render(box.getCenter().getX() - cannonSp.getWidth()/2 - Camera::pos.getX(),box.getCenter().getY() - cannonSp.getHeight()/2 - Camera::pos.getY(),CustomMath::radToDeg(cannonAngle));
}

bool Penguins::isDead(){
	return hp <= 0;
}

void Penguins::shoot(){
    GameBase::getInstance().addObject(new Bullet(box.getCenter().getX(),box.getCenter().getY(),cannonAngle,PENGUINS_BULLET_SPEED,PENGUINS_BULLET_RANGE,"img/penguinshot.png",PENGUINS_BULLET_FRAME_COUNT,PENGUINS_BULLET_FRAME_TIME));
}
