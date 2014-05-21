#include <cstdlib>
#include <iostream>

#include "Game.h"
#include "StageState.h"

using namespace std;

int main(int argc, char **argv){


    Game game("IDJ - Caina 09/0108094", 1024, 600);

    game.push(new StageState());
//    system("pwd");
    game.run();
    return 0;
}

