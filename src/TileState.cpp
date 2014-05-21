#include "TileState.h"

TileState::TileState() : bg("img/title.jpg")
{
}

void TileState::update(float dt){
	input();
}

void TileState::render(){
    bg.render(0,0);
}

void TileState::input(){

	auto& input = InputManager::getInstance();

    if(input.keyPress(ESCAPE_KEY) || input.shouldQuit()){
        hasRequestedQuit = true;
    }

    if(input.keyPress(SPACE_KEY)){
        Game::getInstance().push(new StageState());
    }
}
