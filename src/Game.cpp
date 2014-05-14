#include "Game.h"
#include <iostream>


Game::Game() : GameBase("IDJ - Caina 09/0108094", 1024, 600), bg("img/ocean.jpg"),tileSet(64,64),tileMap("map/tileMap.txt",&tileSet) {

    std::ifstream file ("img/tileset/tilelist.txt");
    std::string str;


    if(file.is_open()){
        while(getline(file,str)){
            tileSet.open("img/tileset/" + str);
        }
    }else{

        throw "Arquivo nao encontrado";
        
    }



    file.close();
}

Game::~Game(){
    Sprite::clear();
    objectArray.clear();
}


void Game::input() {
    
}

void Game::update(){

    int i;
    auto &input = InputManager::getInstance();
    int mouseX = InputManager::getInstance().getMouseX();
    int mouseY = InputManager::getInstance().getMouseY();
    float dt = GameBase::getDeltaTime();

    Camera::update(dt);
    
    if(input.keyPress(ESCAPE_KEY) || input.shouldQuit()){
        shouldQuit = true;
    }

    if(input.keyPress(SPACE_KEY)){

        addObject((float)mouseX + Camera::pos.getX(), (float)mouseY + Camera::pos.getY());
    }

    if (input.isKeyDown(X_KEY)) {
        objectArray.clear();
    }

    if(input.mousePress(LEFT_MOUSE_BUTTON)){
        for(int i = objectArray.size() - 1; i >= 0; --i) {
             Face* face = (Face*) objectArray[i].get();
             if(face->box.isInside((float)mouseX + Camera::pos.getX(), (float)mouseY + Camera::pos.getY())) {
                face->damage(rand() % 10 + 10);
                break;
            }
        }
    }

    

    for(i=0;i<objectArray.size();i++){
        if(objectArray[i]->isDead()){
            objectArray.erase(objectArray.begin()+i);
        }
    }


}

void Game::render(){

    int i;


    bg.render(0,0);

    for(i=0;i<tileMap.getDepth();i++){
         tileMap.renderLayer(i,(i+1)*Camera::pos.getX(),(i+1)*Camera::pos.getY());
    }

    for(i=0;i<objectArray.size();i++){
        objectArray[i]->render();
    }
}


void Game::addObject(float mouseX,float mouseY){
    
    int radius = 200;
    float angle = CustomMath::DegToRad(rand() % 360);

    objectArray.emplace_back(new Face(mouseX + radius*cos(angle),mouseY + radius*sin(angle)));
}

