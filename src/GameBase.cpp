#include "GameBase.h"
#include <iostream>

GameBase* GameBase::instance = nullptr;

GameBase::GameBase(const std::string& title, int width, int height){

    
    srand(time(NULL));
    
    if(instance != nullptr){
        throw "Erro! Ja foi criado instance, chame esse construtor somente 1 vez";
    }
    else
        instance = this;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)!=0){
        throw "erro ao inicializar a biblioteca SDL";
    }
    if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)!=(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)){
        throw "erro ao carregar a biblioteca IMG_Init";
    }
    if((window = SDL_CreateWindow(title.c_str(), 100,100, width, height, 0)) == nullptr){
        throw "nao abriu janela!";
    }
    if((renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == nullptr){
        throw "nao criou renderer";
    }

}

GameBase::~GameBase(){
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    instance = nullptr;
}

void GameBase::run(){
    shouldQuit = false;
    while(!shouldQuit){
        update();
        render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}

SDL_Renderer* GameBase::getRenderer(){
    return renderer;
}

GameBase& GameBase::getInstance(){
    return *instance;
}


