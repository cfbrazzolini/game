#ifndef GAME_H
#define GAME_H

#include "CustomMath.h"
#include "Face.h"
#include "GameBase.h"
#include "Sprite.h"

class Game : public GameBase {
public:
    Game();
    ~Game();
private:
    void input();
    void update();
    void render();
    void addObject(float,float);

    Sprite bg;
};

#endif // GAME_H
