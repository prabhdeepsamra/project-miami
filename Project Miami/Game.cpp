#include "Game.h"

Game::Game(){
    init();
}

Game::~Game(){}

void Game::init(){
    // initializes every gamepiece
    // may not be necessary if we gamepieces calls their own inits
    // from their constructors. we shall see

    gp = new Actor();
}

void Game::update(int delta){
    // Calls update function from every gamepiece
    // delta is milliseconds elapsed since last frame
    gp->update(delta);
}

void Game::draw(){
    //  Calls draw function from every gamepiece
    gp->draw();
}