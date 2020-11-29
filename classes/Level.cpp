//
// Created by georgiana on 24.11.2020.
//

#include "headers/Level.h"

///returns number of waves
int Level::getWave() {
    return currentWave;
}

///returns array of enemies
int * Level::getEnemies() {
    return waves;
}

///returns total number of waves of the level
int Level::getWaveNumber() {
    return nWaves;
}

///get number of enemies to be rendered from the enemy array
int Level::getNextEnemies(int w) {
    if(w<nWaves)
        return waves[w];
    else
        throw "Not sure what this will do. maybe do a bool finished for the level?";
}

///level 1 for easy testing
///do not use except for testing in early stages
Level::Level() {
    level=1;
    nWaves=1;
    reward=10;
    waves=new int[nWaves];
    for(int i=0;i<nWaves;i++)
        waves[i]=(i+1)*level;
    finished=false;
//    board=new Board();
//    board->setBoard(level);
}

///generic constructor
Level::Level(int l, int w, int rew) {
    level=l;
    nWaves=w;
    reward=rew;
    waves=new int[nWaves];
    for(int i=0;i<nWaves;i++)
        waves[i]=(i+1)*level;
    finished=false;
    //board=new Board();
    //board->setBoard(level);
}

///destructor
Level::~Level() {
    delete[] waves;
    finished=true;
}

//todo
///update the current wave and the state of the enemy array and the finished flag
void Level::update() {
    throw "not implemented yet. nu stiu exact ce sa faca";
    /// call .move() for the enemies at every timeout
}


//todo
///reset the level to the original parameters
void Level::reset() {
    throw "not implemented yet";
}




