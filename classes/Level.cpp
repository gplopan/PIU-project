//
// Created by georgiana on 24.11.2020.
//

#include "headers/Level.h"

///returns currentWave
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
    level = 1;
    nWaves = 1;
    reward = 10;
    waves = new int[nWaves];
    for (int i = 0;i < nWaves;i++)
        waves[i] = (i + 1) * level+1;
    this->board.setBoard(1);
    board.getStartPoint(&startX,&startY);
}

///generic constructor
Level::Level(int l, int w, int rew) {
    level = l;
    nWaves = w;
    reward = rew;
    waves = new int[nWaves];
    for (int i = 0;i < nWaves;i++)
        waves[i] = (i + 1) * level;
    board.getStartPoint(&startX,&startY);
}

///destructor
Level::~Level() {
    delete[] waves;
}


//todo
///reset the level to the original parameters
void Level::reset() {
    throw "not implemented yet";
}


int Level::GetAction(int x, int y)
{

    int** _board = this->board.getBoard();
    int pozX = x / 70;
    int pozY = y / 70;

    int data = _board[pozY][pozX];

    if (data == 0)
        _board[pozY][pozX] = 5;
    return data;
}

///returns the value of  the tile at (x,y)
int Level::getPath(int x, int y) {
    return board.getBoard()[x][y];
}

///signals to the StartGame that the level is over
void Level::finishedLevel(){
}

///increments the currentWave variable. if the currentWave is the last one the finishedLevel signal is emitted
void Level::nextWave() {
    currentWave++;
    if(currentWave==nWaves)
        finishedLevel();
}

///return the number of the level
int Level::getLevelNumber() {
    return level;
}

