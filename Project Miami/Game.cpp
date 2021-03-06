#include "Game.h"

Game::Game(){
    init();
}

Game::~Game(){}

void Game::init(){
    // initializes every gamepiece
    // may not be necessary if we gamepieces calls their own inits
    // from their constructors. we shall see

    p = new Player();
    p2 = new Player();

    gp.push_back(p);
    gp.push_back(p2);
}

void Game::update(int delta){
    // Calls update function from every gamepiece
    // delta is milliseconds elapsed since last frame
    p2->moveL();
    for(int i = 0; i < gp.size(); i++)
        gp[i]->update(delta);
}

void Game::draw(){
    //  Calls draw function from every gamepiece
    for(int i = 0; i < gp.size(); i++)
        gp[i]->draw();
}

Player* Game::getPlayerObject(){
    return p;
}

void Game::addKey(unsigned char key){

    if (!keyListContains(key)){
         keyList.push_back(key);
        std:: cout<<"Added " << key <<std::endl;
    }
}
void Game::removeKey(unsigned char key){
    for(int i = 0; i <keyList.size(); i++)
        if(keyList[i] == key){
            keyList.erase(keyList.begin()+i);
            std:: cout<<"Removed " << key <<std::endl;
        }
    }
int Game::keyListSize(){
    return keyList.size();
    }
    
bool Game::keyListContains(unsigned char key){
    bool contains = false;
    for(int i = 0; i <keyList.size(); i++)
        if(keyList[i] == key)
            contains = true;
    return contains;
    }
