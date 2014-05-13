#ifndef GAME_H
#define GAME_H

#include <fstream>

#include "CustomMath.h"
#include "Face.h"
#include "GameBase.h"
#include "MultiTileSet.h"
#include "Sprite.h"
#include "TileMap.h"

class Game : public GameBase {
public:
    Game();
    ~Game();
private:
    void input();
    void update();
    void render();
    void addObject(float,float);
    void buildMap();

    Sprite bg;
    MultiTileSet tileSet;
    TileMap tileMap;
};

#endif // GAME_H
