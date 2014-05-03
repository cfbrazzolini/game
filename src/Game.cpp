#include "Game.h"


Game::Game() : GameBase("IDJ - Caina 09/0108094",1024,600),bg("img/ocean.png"){

}

void Game::update(){
    if(SDL_QuitRequested()){
        shouldQuit = true;
    }
}

void Game::render(){
    //bg.render(0,0);
}
