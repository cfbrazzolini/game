#include "Game.h"


Game::Game() : GameBase("IDJ - Caina 09/0108094", 1024, 600), bg("img/ocean.jpg"){

}

Game::~Game(){
    objectArray.clear();
}


void Game::input() {

    SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event)) {

        // Se o evento for quit, setar a flag para terminação
        if(event.type == SDL_QUIT) {
            shouldQuit = true;
        }
       
        // Se o evento for clique...
        if(event.type == SDL_MOUSEBUTTONDOWN) {

            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for(int i = objectArray.size() - 1; i >= 0; --i) {
                // Obtem o ponteiro e casta pra Face (é provisório, isso é má prática)
                Face* face = (Face*) objectArray[i].get();

                if(face->box.isInside((float)mouseX, (float)mouseY)) {
                    // Aplica dano
                    face->damage(rand() % 10 + 10);
                    // Sai do loop (só queremos acertar um)
                    break;
                }
            }
        }
        if( event.type == SDL_KEYDOWN ) {
            // Se a tecla for ESC, setar a flag de quit
            if( event.key.keysym.sym == SDLK_ESCAPE ) {
                shouldQuit = true;
            }
            // Se não, crie um objeto
            else {
                addObject((float)mouseX, (float)mouseY);
            }
        }
    }
}

void Game::update(){

    int i;
    
    if (SDL_QuitRequested()) {
        shouldQuit = true;
    }


    input();

    for(i=0;i<objectArray.size();i++){
        if(objectArray[i]->isDead()){
            objectArray.erase(objectArray.begin()+i);
        }
    }


}

void Game::render(){

    int i;

    bg.render(0,0);

    for(i=0;i<objectArray.size();i++){
        objectArray[i]->render();
    }
}


void Game::addObject(float mouseX,float mouseY){
    
    int radius = 200;
    float angle = CustomMath::DegToRad(rand() % 360);

    objectArray.emplace_back(new Face(mouseX + radius*cos(angle),mouseY + radius*sin(angle)));
}
