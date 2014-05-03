#include "Sprite.h"

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(const std::string& file){
    texture = nullptr;
    open(file);
}

Sprite::~Sprite(){
    if(isOpen()){
        SDL_DestroyTexture(texture);
    }
}

void Sprite::open(const std::string& file){
    if(isOpen()){
        SDL_DestroyTexture(texture);
    }
    if((texture=IMG_LoadTexture(GameBase::getInstance().getRenderer(), file.c_str()))==nullptr){
        printf("nao foi possivel carregar a texture %s\n", file.c_str());
        printf("%s\n",SDL_GetError());
        return;
    }
    SDL_QueryTexture(texture, nullptr, nullptr, &dimensions.w, &dimensions.h);
    setClip(0,0, dimensions.w, dimensions.h);
}

void Sprite::setClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::render(int x, int y){

    if(!isOpen()){
        return;
    }
    SDL_Rect dstRect;

    dstRect = dimensions;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = clipRect.w;
    dstRect.h = clipRect.h;

    SDL_RenderCopy(GameBase::getInstance().getRenderer(), texture, &clipRect, &dstRect);
}

int Sprite::getWidth(){
    return dimensions.w;
}

int Sprite::getHeight(){
    return dimensions.h;
}

bool Sprite::isOpen(){
    return texture != nullptr;
}



