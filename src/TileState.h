#ifndef TILESTATE_H
#define TILESTATE_H

#include "InputManager.h"
#include "Sprite.h"
#include "StageState.h"
#include "State.h"


class TileState : public State
{
public:
    TileState();
    void update(float);
    void render();
private:
	void input();

	Sprite bg;
};

#endif // TILESTATE_H
