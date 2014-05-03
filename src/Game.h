#ifndef GAME_H
#define GAME_H

#include "GameBase.h"
#include "Sprite.h"

class Game : public GameBase {
public:
    Game();
private:
    void update();
    void render();

    Sprite bg;
};

#endif // GAME_H
