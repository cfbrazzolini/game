#include "Game.h"
#include <iostream>


Game::Game() : GameBase("IDJ - Caina 09/0108094", 1024, 600), bg("img/ocean.jpg"),tileSet(64,64),tileMap(25,25,2,&tileSet) {

    std::ifstream file ("img/tileset/tilelist.txt");
    std::string str;

    buildMap();


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
    tileMap.render(Camera::pos.getX(),Camera::pos.getY());

    for(i=0;i<objectArray.size();i++){
        objectArray[i]->render();
    }
}


void Game::addObject(float mouseX,float mouseY){
    
    int radius = 200;
    float angle = CustomMath::DegToRad(rand() % 360);

    objectArray.emplace_back(new Face(mouseX + radius*cos(angle),mouseY + radius*sin(angle)));
}

void Game::buildMap() {

    tileMap.at(0, 0) = 4;
    tileMap.at(1, 0) = 3;
    tileMap.at(2, 0) = 3;
    tileMap.at(3, 0) = 5;
    tileMap.at(4, 0) = 4;
    tileMap.at(5, 0) = 5;
    tileMap.at(6, 0) = 4;
    tileMap.at(7, 0) = 3;
    tileMap.at(8, 0) = 3;
    tileMap.at(9, 0) = 3;
    tileMap.at(10, 0) = 3;
    tileMap.at(11, 0) = 3;
    tileMap.at(12, 0) = 3;
    tileMap.at(13, 0) = 5;
    tileMap.at(14, 0) = 4;
    tileMap.at(15, 0) = 3;
    tileMap.at(16, 0) = 3;
    tileMap.at(17, 0) = 5;
    tileMap.at(18, 0) = 4;
    tileMap.at(19, 0) = 3;
    tileMap.at(20, 0) = 3;
    tileMap.at(21, 0) = 5;
    tileMap.at(22, 0) = -1;
    tileMap.at(23, 0) = -1;
    tileMap.at(24, 0) = -1;
    tileMap.at(0, 1) = 10;
    tileMap.at(1, 1) = 3;
    tileMap.at(2, 1) = 3;
    tileMap.at(3, 1) = 9;
    tileMap.at(4, 1) = 15;
    tileMap.at(5, 1) = 9;
    tileMap.at(6, 1) = 3;
    tileMap.at(7, 1) = 3;
    tileMap.at(8, 1) = 3;
    tileMap.at(9, 1) = 3;
    tileMap.at(10, 1) = 3;
    tileMap.at(11, 1) = 3;
    tileMap.at(12, 1) = 3;
    tileMap.at(13, 1) = 3;
    tileMap.at(14, 1) = 3;
    tileMap.at(15, 1) = 9;
    tileMap.at(16, 1) = 3;
    tileMap.at(17, 1) = 3;
    tileMap.at(18, 1) = 3;
    tileMap.at(19, 1) = 3;
    tileMap.at(20, 1) = 3;
    tileMap.at(21, 1) = 11;
    tileMap.at(22, 1) = -1;
    tileMap.at(23, 1) = -1;
    tileMap.at(24, 1) = -1;
    tileMap.at(0, 2) = 4;
    tileMap.at(1, 2) = 3;
    tileMap.at(2, 2) = 0;
    tileMap.at(3, 2) = 1;
    tileMap.at(4, 2) = 2;
    tileMap.at(5, 2) = 3;
    tileMap.at(6, 2) = 0;
    tileMap.at(7, 2) = 1;
    tileMap.at(8, 2) = 1;
    tileMap.at(9, 2) = 1;
    tileMap.at(10, 2) = 1;
    tileMap.at(11, 2) = 1;
    tileMap.at(12, 2) = 1;
    tileMap.at(13, 2) = 2;
    tileMap.at(14, 2) = 3;
    tileMap.at(15, 2) = 0;
    tileMap.at(16, 2) = 1;
    tileMap.at(17, 2) = 1;
    tileMap.at(18, 2) = 1;
    tileMap.at(19, 2) = 2;
    tileMap.at(20, 2) = 3;
    tileMap.at(21, 2) = 5;
    tileMap.at(22, 2) = -1;
    tileMap.at(23, 2) = -1;
    tileMap.at(24, 2) = -1;
    tileMap.at(0, 3) = 10;
    tileMap.at(1, 3) = 3;
    tileMap.at(2, 3) = 6;
    tileMap.at(3, 3) = 7;
    tileMap.at(4, 3) = 8;
    tileMap.at(5, 3) = 3;
    tileMap.at(6, 3) = 6;
    tileMap.at(7, 3) = 7;
    tileMap.at(8, 3) = 7;
    tileMap.at(9, 3) = 7;
    tileMap.at(10, 3) = 7;
    tileMap.at(11, 3) = 7;
    tileMap.at(12, 3) = 7;
    tileMap.at(13, 3) = 8;
    tileMap.at(14, 3) = 15;
    tileMap.at(15, 3) = 6;
    tileMap.at(16, 3) = 7;
    tileMap.at(17, 3) = 7;
    tileMap.at(18, 3) = 7;
    tileMap.at(19, 3) = 8;
    tileMap.at(20, 3) = 3;
    tileMap.at(21, 3) = 11;
    tileMap.at(22, 3) = -1;
    tileMap.at(23, 3) = -1;
    tileMap.at(24, 3) = -1;
    tileMap.at(0, 4) = 4;
    tileMap.at(1, 4) = 3;
    tileMap.at(2, 4) = 6;
    tileMap.at(3, 4) = 7;
    tileMap.at(4, 4) = 8;
    tileMap.at(5, 4) = 3;
    tileMap.at(6, 4) = 6;
    tileMap.at(7, 4) = 7;
    tileMap.at(8, 4) = 7;
    tileMap.at(9, 4) = 7;
    tileMap.at(10, 4) = 7;
    tileMap.at(11, 4) = 7;
    tileMap.at(12, 4) = 7;
    tileMap.at(13, 4) = 8;
    tileMap.at(14, 4) = 3;
    tileMap.at(15, 4) = 6;
    tileMap.at(16, 4) = 7;
    tileMap.at(17, 4) = 7;
    tileMap.at(18, 4) = 7;
    tileMap.at(19, 4) = 8;
    tileMap.at(20, 4) = 15;
    tileMap.at(21, 4) = 5;
    tileMap.at(22, 4) = -1;
    tileMap.at(23, 4) = -1;
    tileMap.at(24, 4) = -1;
    tileMap.at(0, 5) = 10;
    tileMap.at(1, 5) = 3;
    tileMap.at(2, 5) = 6;
    tileMap.at(3, 5) = 7;
    tileMap.at(4, 5) = 8;
    tileMap.at(5, 5) = 3;
    tileMap.at(6, 5) = 12;
    tileMap.at(7, 5) = 13;
    tileMap.at(8, 5) = 13;
    tileMap.at(9, 5) = 13;
    tileMap.at(10, 5) = 13;
    tileMap.at(11, 5) = 13;
    tileMap.at(12, 5) = 13;
    tileMap.at(13, 5) = 14;
    tileMap.at(14, 5) = 3;
    tileMap.at(15, 5) = 12;
    tileMap.at(16, 5) = 13;
    tileMap.at(17, 5) = 13;
    tileMap.at(18, 5) = 13;
    tileMap.at(19, 5) = 14;
    tileMap.at(20, 5) = 3;
    tileMap.at(21, 5) = 3;
    tileMap.at(22, 5) = -1;
    tileMap.at(23, 5) = -1;
    tileMap.at(24, 5) = -1;
    tileMap.at(0, 6) = 4;
    tileMap.at(1, 6) = 3;
    tileMap.at(2, 6) = 12;
    tileMap.at(3, 6) = 13;
    tileMap.at(4, 6) = 14;
    tileMap.at(5, 6) = 3;
    tileMap.at(6, 6) = 3;
    tileMap.at(7, 6) = 3;
    tileMap.at(8, 6) = 9;
    tileMap.at(9, 6) = 3;
    tileMap.at(10, 6) = 3;
    tileMap.at(11, 6) = 3;
    tileMap.at(12, 6) = 3;
    tileMap.at(13, 6) = 3;
    tileMap.at(14, 6) = 3;
    tileMap.at(15, 6) = 3;
    tileMap.at(16, 6) = 3;
    tileMap.at(17, 6) = 3;
    tileMap.at(18, 6) = 3;
    tileMap.at(19, 6) = 3;
    tileMap.at(20, 6) = 3;
    tileMap.at(21, 6) = 3;
    tileMap.at(22, 6) = -1;
    tileMap.at(23, 6) = -1;
    tileMap.at(24, 6) = -1;
    tileMap.at(0, 7) = 3;
    tileMap.at(1, 7) = 3;
    tileMap.at(2, 7) = 3;
    tileMap.at(3, 7) = 3;
    tileMap.at(4, 7) = 3;
    tileMap.at(5, 7) = 9;
    tileMap.at(6, 7) = 3;
    tileMap.at(7, 7) = 3;
    tileMap.at(8, 7) = 3;
    tileMap.at(9, 7) = 3;
    tileMap.at(10, 7) = 15;
    tileMap.at(11, 7) = 3;
    tileMap.at(12, 7) = 3;
    tileMap.at(13, 7) = 0;
    tileMap.at(14, 7) = 1;
    tileMap.at(15, 7) = 1;
    tileMap.at(16, 7) = 1;
    tileMap.at(17, 7) = 1;
    tileMap.at(18, 7) = 1;
    tileMap.at(19, 7) = 2;
    tileMap.at(20, 7) = 3;
    tileMap.at(21, 7) = 11;
    tileMap.at(22, 7) = -1;
    tileMap.at(23, 7) = -1;
    tileMap.at(24, 7) = -1;
    tileMap.at(0, 8) = 3;
    tileMap.at(1, 8) = 3;
    tileMap.at(2, 8) = 0;
    tileMap.at(3, 8) = 1;
    tileMap.at(4, 8) = 1;
    tileMap.at(5, 8) = 1;
    tileMap.at(6, 8) = 1;
    tileMap.at(7, 8) = 1;
    tileMap.at(8, 8) = 1;
    tileMap.at(9, 8) = 1;
    tileMap.at(10, 8) = 1;
    tileMap.at(11, 8) = 2;
    tileMap.at(12, 8) = 3;
    tileMap.at(13, 8) = 6;
    tileMap.at(14, 8) = 7;
    tileMap.at(15, 8) = 7;
    tileMap.at(16, 8) = 7;
    tileMap.at(17, 8) = 7;
    tileMap.at(18, 8) = 7;
    tileMap.at(19, 8) = 8;
    tileMap.at(20, 8) = 3;
    tileMap.at(21, 8) = 5;
    tileMap.at(22, 8) = -1;
    tileMap.at(23, 8) = -1;
    tileMap.at(24, 8) = -1;
    tileMap.at(0, 9) = 3;
    tileMap.at(1, 9) = 9;
    tileMap.at(2, 9) = 6;
    tileMap.at(3, 9) = 7;
    tileMap.at(4, 9) = 7;
    tileMap.at(5, 9) = 7;
    tileMap.at(6, 9) = 7;
    tileMap.at(7, 9) = 7;
    tileMap.at(8, 9) = 7;
    tileMap.at(9, 9) = 7;
    tileMap.at(10, 9) = 7;
    tileMap.at(11, 9) = 8;
    tileMap.at(12, 9) = 3;
    tileMap.at(13, 9) = 6;
    tileMap.at(14, 9) = 7;
    tileMap.at(15, 9) = 7;
    tileMap.at(16, 9) = 7;
    tileMap.at(17, 9) = 7;
    tileMap.at(18, 9) = 7;
    tileMap.at(19, 9) = 8;
    tileMap.at(20, 9) = 15;
    tileMap.at(21, 9) = 11;
    tileMap.at(22, 9) = -1;
    tileMap.at(23, 9) = -1;
    tileMap.at(24, 9) = -1;
    tileMap.at(0, 10) = 3;
    tileMap.at(1, 10) = 15;
    tileMap.at(2, 10) = 6;
    tileMap.at(3, 10) = 7;
    tileMap.at(4, 10) = 7;
    tileMap.at(5, 10) = 7;
    tileMap.at(6, 10) = 7;
    tileMap.at(7, 10) = 7;
    tileMap.at(8, 10) = 7;
    tileMap.at(9, 10) = 7;
    tileMap.at(10, 10) = 7;
    tileMap.at(11, 10) = 8;
    tileMap.at(12, 10) = 3;
    tileMap.at(13, 10) = 6;
    tileMap.at(14, 10) = 7;
    tileMap.at(15, 10) = 7;
    tileMap.at(16, 10) = 7;
    tileMap.at(17, 10) = 7;
    tileMap.at(18, 10) = 7;
    tileMap.at(19, 10) = 8;
    tileMap.at(20, 10) = 15;
    tileMap.at(21, 10) = 5;
    tileMap.at(22, 10) = -1;
    tileMap.at(23, 10) = -1;
    tileMap.at(24, 10) = -1;
    tileMap.at(0, 11) = 3;
    tileMap.at(1, 11) = 3;
    tileMap.at(2, 11) = 6;
    tileMap.at(3, 11) = 7;
    tileMap.at(4, 11) = 7;
    tileMap.at(5, 11) = 7;
    tileMap.at(6, 11) = 7;
    tileMap.at(7, 11) = 7;
    tileMap.at(8, 11) = 7;
    tileMap.at(9, 11) = 7;
    tileMap.at(10, 11) = 7;
    tileMap.at(11, 11) = 8;
    tileMap.at(12, 11) = 3;
    tileMap.at(13, 11) = 6;
    tileMap.at(14, 11) = 7;
    tileMap.at(15, 11) = 7;
    tileMap.at(16, 11) = 7;
    tileMap.at(17, 11) = 7;
    tileMap.at(18, 11) = 7;
    tileMap.at(19, 11) = 8;
    tileMap.at(20, 11) = 3;
    tileMap.at(21, 11) = 11;
    tileMap.at(22, 11) = -1;
    tileMap.at(23, 11) = -1;
    tileMap.at(24, 11) = -1;
    tileMap.at(0, 12) = 3;
    tileMap.at(1, 12) = 3;
    tileMap.at(2, 12) = 6;
    tileMap.at(3, 12) = 7;
    tileMap.at(4, 12) = 7;
    tileMap.at(5, 12) = 7;
    tileMap.at(6, 12) = 7;
    tileMap.at(7, 12) = 7;
    tileMap.at(8, 12) = 7;
    tileMap.at(9, 12) = 7;
    tileMap.at(10, 12) = 7;
    tileMap.at(11, 12) = 8;
    tileMap.at(12, 12) = 3;
    tileMap.at(13, 12) = 6;
    tileMap.at(14, 12) = 7;
    tileMap.at(15, 12) = 7;
    tileMap.at(16, 12) = 7;
    tileMap.at(17, 12) = 7;
    tileMap.at(18, 12) = 7;
    tileMap.at(19, 12) = 8;
    tileMap.at(20, 12) = 3;
    tileMap.at(21, 12) = 5;
    tileMap.at(22, 12) = -1;
    tileMap.at(23, 12) = -1;
    tileMap.at(24, 12) = -1;
    tileMap.at(0, 13) = 10;
    tileMap.at(1, 13) = 3;
    tileMap.at(2, 13) = 6;
    tileMap.at(3, 13) = 7;
    tileMap.at(4, 13) = 7;
    tileMap.at(5, 13) = 7;
    tileMap.at(6, 13) = 7;
    tileMap.at(7, 13) = 7;
    tileMap.at(8, 13) = 7;
    tileMap.at(9, 13) = 7;
    tileMap.at(10, 13) = 7;
    tileMap.at(11, 13) = 8;
    tileMap.at(12, 13) = 9;
    tileMap.at(13, 13) = 6;
    tileMap.at(14, 13) = 7;
    tileMap.at(15, 13) = 7;
    tileMap.at(16, 13) = 7;
    tileMap.at(17, 13) = 7;
    tileMap.at(18, 13) = 7;
    tileMap.at(19, 13) = 8;
    tileMap.at(20, 13) = 3;
    tileMap.at(21, 13) = 11;
    tileMap.at(22, 13) = -1;
    tileMap.at(23, 13) = -1;
    tileMap.at(24, 13) = -1;
    tileMap.at(0, 14) = 4;
    tileMap.at(1, 14) = 3;
    tileMap.at(2, 14) = 6;
    tileMap.at(3, 14) = 7;
    tileMap.at(4, 14) = 7;
    tileMap.at(5, 14) = 7;
    tileMap.at(6, 14) = 7;
    tileMap.at(7, 14) = 7;
    tileMap.at(8, 14) = 7;
    tileMap.at(9, 14) = 7;
    tileMap.at(10, 14) = 7;
    tileMap.at(11, 14) = 8;
    tileMap.at(12, 14) = 15;
    tileMap.at(13, 14) = 6;
    tileMap.at(14, 14) = 7;
    tileMap.at(15, 14) = 7;
    tileMap.at(16, 14) = 7;
    tileMap.at(17, 14) = 7;
    tileMap.at(18, 14) = 7;
    tileMap.at(19, 14) = 8;
    tileMap.at(20, 14) = 3;
    tileMap.at(21, 14) = 5;
    tileMap.at(22, 14) = -1;
    tileMap.at(23, 14) = -1;
    tileMap.at(24, 14) = -1;
    tileMap.at(0, 15) = 10;
    tileMap.at(1, 15) = 3;
    tileMap.at(2, 15) = 6;
    tileMap.at(3, 15) = 7;
    tileMap.at(4, 15) = 7;
    tileMap.at(5, 15) = 7;
    tileMap.at(6, 15) = 7;
    tileMap.at(7, 15) = 7;
    tileMap.at(8, 15) = 7;
    tileMap.at(9, 15) = 7;
    tileMap.at(10, 15) = 7;
    tileMap.at(11, 15) = 8;
    tileMap.at(12, 15) = 15;
    tileMap.at(13, 15) = 6;
    tileMap.at(14, 15) = 7;
    tileMap.at(15, 15) = 7;
    tileMap.at(16, 15) = 7;
    tileMap.at(17, 15) = 7;
    tileMap.at(18, 15) = 7;
    tileMap.at(19, 15) = 8;
    tileMap.at(20, 15) = 3;
    tileMap.at(21, 15) = 11;
    tileMap.at(22, 15) = -1;
    tileMap.at(23, 15) = -1;
    tileMap.at(24, 15) = -1;
    tileMap.at(0, 16) = 4;
    tileMap.at(1, 16) = 3;
    tileMap.at(2, 16) = 6;
    tileMap.at(3, 16) = 7;
    tileMap.at(4, 16) = 7;
    tileMap.at(5, 16) = 7;
    tileMap.at(6, 16) = 7;
    tileMap.at(7, 16) = 7;
    tileMap.at(8, 16) = 7;
    tileMap.at(9, 16) = 7;
    tileMap.at(10, 16) = 7;
    tileMap.at(11, 16) = 8;
    tileMap.at(12, 16) = 3;
    tileMap.at(13, 16) = 6;
    tileMap.at(14, 16) = 7;
    tileMap.at(15, 16) = 7;
    tileMap.at(16, 16) = 7;
    tileMap.at(17, 16) = 7;
    tileMap.at(18, 16) = 7;
    tileMap.at(19, 16) = 8;
    tileMap.at(20, 16) = 9;
    tileMap.at(21, 16) = 5;
    tileMap.at(22, 16) = -1;
    tileMap.at(23, 16) = -1;
    tileMap.at(24, 16) = -1;
    tileMap.at(0, 17) = 3;
    tileMap.at(1, 17) = 3;
    tileMap.at(2, 17) = 12;
    tileMap.at(3, 17) = 13;
    tileMap.at(4, 17) = 13;
    tileMap.at(5, 17) = 13;
    tileMap.at(6, 17) = 13;
    tileMap.at(7, 17) = 13;
    tileMap.at(8, 17) = 13;
    tileMap.at(9, 17) = 13;
    tileMap.at(10, 17) = 13;
    tileMap.at(11, 17) = 14;
    tileMap.at(12, 17) = 3;
    tileMap.at(13, 17) = 12;
    tileMap.at(14, 17) = 13;
    tileMap.at(15, 17) = 13;
    tileMap.at(16, 17) = 13;
    tileMap.at(17, 17) = 13;
    tileMap.at(18, 17) = 13;
    tileMap.at(19, 17) = 14;
    tileMap.at(20, 17) = 9;
    tileMap.at(21, 17) = 3;
    tileMap.at(22, 17) = -1;
    tileMap.at(23, 17) = -1;
    tileMap.at(24, 17) = -1;
    tileMap.at(0, 18) = 3;
    tileMap.at(1, 18) = 3;
    tileMap.at(2, 18) = 3;
    tileMap.at(3, 18) = 3;
    tileMap.at(4, 18) = 3;
    tileMap.at(5, 18) = 3;
    tileMap.at(6, 18) = 3;
    tileMap.at(7, 18) = 3;
    tileMap.at(8, 18) = 15;
    tileMap.at(9, 18) = 3;
    tileMap.at(10, 18) = 3;
    tileMap.at(11, 18) = 9;
    tileMap.at(12, 18) = 3;
    tileMap.at(13, 18) = 9;
    tileMap.at(14, 18) = 3;
    tileMap.at(15, 18) = 3;
    tileMap.at(16, 18) = 3;
    tileMap.at(17, 18) = 3;
    tileMap.at(18, 18) = 3;
    tileMap.at(19, 18) = 3;
    tileMap.at(20, 18) = 3;
    tileMap.at(21, 18) = 3;
    tileMap.at(22, 18) = -1;
    tileMap.at(23, 18) = -1;
    tileMap.at(24, 18) = -1;
    tileMap.at(0, 19) = 10;
    tileMap.at(1, 19) = 11;
    tileMap.at(2, 19) = 10;
    tileMap.at(3, 19) = 11;
    tileMap.at(4, 19) = 10;
    tileMap.at(5, 19) = 3;
    tileMap.at(6, 19) = 3;
    tileMap.at(7, 19) = 11;
    tileMap.at(8, 19) = 10;
    tileMap.at(9, 19) = 3;
    tileMap.at(10, 19) = 3;
    tileMap.at(11, 19) = 3;
    tileMap.at(12, 19) = 3;
    tileMap.at(13, 19) = 3;
    tileMap.at(14, 19) = 3;
    tileMap.at(15, 19) = 11;
    tileMap.at(16, 19) = 10;
    tileMap.at(17, 19) = 3;
    tileMap.at(18, 19) = 3;
    tileMap.at(19, 19) = 3;
    tileMap.at(20, 19) = 3;
    tileMap.at(21, 19) = 11;
    tileMap.at(22, 19) = -1;
    tileMap.at(23, 19) = -1;
    tileMap.at(24, 19) = -1;
    tileMap.at(0, 20) = -1;
    tileMap.at(1, 20) = -1;
    tileMap.at(2, 20) = -1;
    tileMap.at(3, 20) = -1;
    tileMap.at(4, 20) = -1;
    tileMap.at(5, 20) = 10;
    tileMap.at(6, 20) = 11;
    tileMap.at(7, 20) = -1;
    tileMap.at(8, 20) = -1;
    tileMap.at(9, 20) = -1;
    tileMap.at(10, 20) = -1;
    tileMap.at(11, 20) = 10;
    tileMap.at(12, 20) = 11;
    tileMap.at(13, 20) = -1;
    tileMap.at(14, 20) = -1;
    tileMap.at(15, 20) = -1;
    tileMap.at(16, 20) = -1;
    tileMap.at(17, 20) = 10;
    tileMap.at(18, 20) = 11;
    tileMap.at(19, 20) = -1;
    tileMap.at(20, 20) = -1;
    tileMap.at(21, 20) = -1;
    tileMap.at(22, 20) = -1;
    tileMap.at(23, 20) = -1;
    tileMap.at(24, 20) = -1;
    tileMap.at(0, 21) = -1;
    tileMap.at(1, 21) = 4;
    tileMap.at(2, 21) = 5;
    tileMap.at(3, 21) = -1;
    tileMap.at(4, 21) = -1;
    tileMap.at(5, 21) = -1;
    tileMap.at(6, 21) = -1;
    tileMap.at(7, 21) = -1;
    tileMap.at(8, 21) = -1;
    tileMap.at(9, 21) = -1;
    tileMap.at(10, 21) = -1;
    tileMap.at(11, 21) = -1;
    tileMap.at(12, 21) = -1;
    tileMap.at(13, 21) = -1;
    tileMap.at(14, 21) = -1;
    tileMap.at(15, 21) = -1;
    tileMap.at(16, 21) = -1;
    tileMap.at(17, 21) = -1;
    tileMap.at(18, 21) = -1;
    tileMap.at(19, 21) = -1;
    tileMap.at(20, 21) = -1;
    tileMap.at(21, 21) = -1;
    tileMap.at(22, 21) = -1;
    tileMap.at(23, 21) = -1;
    tileMap.at(24, 21) = -1;
    tileMap.at(0, 22) = -1;
    tileMap.at(1, 22) = 9;
    tileMap.at(2, 22) = 3;
    tileMap.at(3, 22) = -1;
    tileMap.at(4, 22) = -1;
    tileMap.at(5, 22) = -1;
    tileMap.at(6, 22) = -1;
    tileMap.at(7, 22) = -1;
    tileMap.at(8, 22) = -1;
    tileMap.at(9, 22) = -1;
    tileMap.at(10, 22) = -1;
    tileMap.at(11, 22) = -1;
    tileMap.at(12, 22) = -1;
    tileMap.at(13, 22) = -1;
    tileMap.at(14, 22) = -1;
    tileMap.at(15, 22) = -1;
    tileMap.at(16, 22) = -1;
    tileMap.at(17, 22) = -1;
    tileMap.at(18, 22) = 4;
    tileMap.at(19, 22) = 5;
    tileMap.at(20, 22) = -1;
    tileMap.at(21, 22) = -1;
    tileMap.at(22, 22) = -1;
    tileMap.at(23, 22) = -1;
    tileMap.at(24, 22) = -1;
    tileMap.at(0, 23) = -1;
    tileMap.at(1, 23) = 10;
    tileMap.at(2, 23) = 11;
    tileMap.at(3, 23) = -1;
    tileMap.at(4, 23) = -1;
    tileMap.at(5, 23) = -1;
    tileMap.at(6, 23) = -1;
    tileMap.at(7, 23) = -1;
    tileMap.at(8, 23) = -1;
    tileMap.at(9, 23) = -1;
    tileMap.at(10, 23) = -1;
    tileMap.at(11, 23) = -1;
    tileMap.at(12, 23) = -1;
    tileMap.at(13, 23) = -1;
    tileMap.at(14, 23) = -1;
    tileMap.at(15, 23) = -1;
    tileMap.at(16, 23) = -1;
    tileMap.at(17, 23) = -1;
    tileMap.at(18, 23) = 10;
    tileMap.at(19, 23) = 11;
    tileMap.at(20, 23) = -1;
    tileMap.at(21, 23) = -1;
    tileMap.at(22, 23) = -1;
    tileMap.at(23, 23) = -1;
    tileMap.at(24, 23) = -1;
    tileMap.at(0, 24) = -1;
    tileMap.at(1, 24) = -1;
    tileMap.at(2, 24) = -1;
    tileMap.at(3, 24) = -1;
    tileMap.at(4, 24) = -1;
    tileMap.at(5, 24) = -1;
    tileMap.at(6, 24) = -1;
    tileMap.at(7, 24) = -1;
    tileMap.at(8, 24) = -1;
    tileMap.at(9, 24) = -1;
    tileMap.at(10, 24) = -1;
    tileMap.at(11, 24) = -1;
    tileMap.at(12, 24) = -1;
    tileMap.at(13, 24) = -1;
    tileMap.at(14, 24) = -1;
    tileMap.at(15, 24) = -1;
    tileMap.at(16, 24) = -1;
    tileMap.at(17, 24) = -1;
    tileMap.at(18, 24) = -1;
    tileMap.at(19, 24) = -1;
    tileMap.at(20, 24) = -1;
    tileMap.at(21, 24) = -1;
    tileMap.at(22, 24) = -1;
    tileMap.at(23, 24) = -1;
    tileMap.at(24, 24) = -1;

}