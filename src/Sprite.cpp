#include "Sprite.h"


std::unordered_map<std::string,SDL_Texture*> Sprite::assetTable;

Sprite::Sprite(){
    texture = nullptr;
    scaleX = 1;
    scaleY = 1;
}

Sprite::Sprite(const std::string& file){
    texture = nullptr;
    scaleX = 1;
    scaleY = 1;
    open(file);
}

Sprite::~Sprite(){
    
}

void Sprite::open(const std::string& file){

    if(assetTable.find(file) == assetTable.end()){
        if((texture=IMG_LoadTexture(GameBase::getInstance().getRenderer(), file.c_str()))==nullptr){
            printf("nao foi possivel carregar a texture %s\n", file.c_str());
            printf("%s\n",SDL_GetError());
            return;
        }else{
            assetTable.emplace(file,texture);
        }

    }else{
        texture = assetTable[file];
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

void Sprite::render(int x, int y,float angle){

    if(!isOpen()){
        return;
    }
    SDL_Rect dstRect;

    dstRect = dimensions;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = clipRect.w*scaleX;
    dstRect.h = clipRect.h*scaleY;

    SDL_RenderCopyEx(GameBase::getInstance().getRenderer(), texture, &clipRect, &dstRect,angle,NULL,SDL_FLIP_NONE);
}

int Sprite::getWidth(){
    return dimensions.w*scaleX;
}

int Sprite::getHeight(){
    return dimensions.h*scaleY;
}

bool Sprite::isOpen(){
    return texture != nullptr;
}


void Sprite::clear(){
    
    for ( auto it = assetTable.begin(); it!= assetTable.end(); ++it ){
       SDL_DestroyTexture(it->second);
    }

    assetTable.clear();
}


void Sprite::setScaleX(float scale){
    scaleX = scale;
}

void Sprite::setScaleY(float scale){
    scaleY = scale;
}

void Sprite::setScale(float scale){

    scaleX = scale;
    scaleY = scale;

}

