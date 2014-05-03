#ifndef GAMEBASE_H
#define GAMEBASE_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

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
private:
    static GameBase* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;

};

#endif // GAMEBASE_H


