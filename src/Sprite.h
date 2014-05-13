#ifndef SPRITE_H
#define SPRITE_H

#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <unordered_map>

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
    static void clear();

private:
    static std::unordered_map<std::string, SDL_Texture*> assetTable;
    SDL_Texture* texture;
    SDL_Rect dimensions;
protected:
    SDL_Rect clipRect;
};


#endif // SPRITE_H
