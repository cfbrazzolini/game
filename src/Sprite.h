#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#include "SDL.h"

class Sprite
{
public:
    Sprite();
    Sprite(const std::string&);
    ~Sprite();
    void open(const std::string&);
    void setClip(int,int,int,int);
    void render(int,int);
    int getWidth();
    int getHeight();
    bool isOpen();
private:
    SDL_Texture* texture;
    SDL_Rect dimensions;
    SDL_Rect clipRect;
};

#endif // SPRITE_H
