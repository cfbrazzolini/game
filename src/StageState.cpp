#include "StageState.h"


StageState::StageState() : bg("img/ocean.jpg"),tileSet(64,64,"img/tileset.png"),tileMap("map/tileMap.txt",&tileSet) {

    Penguins* penguin = new Penguins(512,600);


    Camera::follow(penguin);

    objectArray.emplace_back(new Alien(512,300,4));
    objectArray.emplace_back(new Alien(800,300,6));
    objectArray.emplace_back(penguin);
}

StageState::~StageState(){
    Sprite::clear();
    objectArray.clear();
}


void StageState::input() {
    
}

void StageState::update(float dt){

    int i,j;
    auto &input = InputManager::getInstance();
    int mouseX = InputManager::getInstance().getMouseX();
    int mouseY = InputManager::getInstance().getMouseY();
    //float dt = Game::getDeltaTime();

    if(Penguins::player == nullptr){
        Camera::unfollow();
    }

    Camera::update(dt);
    
    if(input.keyPress(ESCAPE_KEY) || input.shouldQuit()){
        hasRequestedQuit = true;
    }

    if(input.keyPress(SPACE_KEY)){

        //addObject((float)mouseX + Camera::pos.getX(), (float)mouseY + Camera::pos.getY());
    }

    if (input.isKeyDown(X_KEY)) {
        objectArray.clear();
    }


    
    updateArray(dt);
    

    for(i = 0; i < objectArray.size(); i++) {
       for (j = i; j < objectArray.size(); j++)       {
            if(Collision::IsColliding(objectArray[i]->box,objectArray[j]->box,objectArray[i]->rotation,objectArray[j]->rotation)){
                objectArray[i]->notifyCollision(*objectArray[j]);
                objectArray[j]->notifyCollision(*objectArray[i]);
            }
       }
    }

    

    for(i=0;i<objectArray.size();i++){
        if(objectArray[i]->isDead()){
            objectArray.erase(objectArray.begin()+i);
        }
    }


}

void StageState::render(){

    int i;


    bg.render(0,0);

    for(i=0;i<tileMap.getDepth();i++){
         tileMap.renderLayer(i,(i+1)*Camera::pos.getX(),(i+1)*Camera::pos.getY());
    }

    renderArray();
}

/*
void StageState::addObject(float mouseX,float mouseY){
    

}
*/
