#ifndef SPRITE_H
#define SPRITE_H

#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "GameBase.h"


class Sprite{
public:
    Sprite();
    Sprite(const std::string&);
    virtual ~Sprite();
    void open(const std::string&);
    void setClip(int, int, int, int);
    void render(int, int);
    int getWidth();
    int getHeight();
    bool isOpen();
private:
    SDL_Texture* texture;
    SDL_Rect dimensions;
protected:
    SDL_Rect clipRect;
};


#endif // SPRITE_H
