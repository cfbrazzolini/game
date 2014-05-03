#include "Game.h"


Game::Game() : GameBase("IDJ - Caina 09/0108094", 1024, 600), bg("img/ocean.jpg"){

}

void Game::update(){
    if(SDL_QuitRequested() != 0){
        shouldQuit = true;
    }
}

void Game::render(){
    bg.render(0,0);
}
