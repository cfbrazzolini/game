#ifndef GAMEBASE_H
#define GAMEBASE_H

#include <memory>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <ctime>
#include <vector>

#include "GameObject.h"
#include "InputManager.h"


class GameBase{
public:
    void run();
    SDL_Renderer* getRenderer();
    static GameBase& getInstance();
protected:
    GameBase(const std::string&, int, int);
    virtual ~GameBase();
    virtual void update() = 0;
    virtual void render() = 0;
    bool shouldQuit;

    std::vector<std::unique_ptr<GameObject>> objectArray;
private:
    static GameBase* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;

};

#endif // GAMEBASE_H

