//
// Created by georgiana on 24.11.2020.
//

#include "../headers/Level.h"

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

///get number of enemies to be rendered from the enemy array. does not modify any variables
int Level::getNextEnemies(int w) {
    if(w<nWaves)
        return waves[w];
    else
        return 0;
}

///level 1 for easy testing
///do not use except for testing in early stages
Level::Level() {
    level = 1;
    nWaves = 2;
    reward = 10;
    waves = new int[nWaves];
    for (int i = 0;i < nWaves;i++)
        waves[i] = (i + 1) * level+1;
    this->board.setBoard(level);
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
    this->board.setBoard(level);
    board.getStartPoint(&startX,&startY);
}

///destructor
Level::~Level() {
    delete[] waves;
}

///probes the board for towers at (x,y) , modifies accordingly
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


///brings the level back to the original parameters
void Level::resetLevel(int level) {
    this->level=level;
    currentWave=0;
    board.setBoard(level);
}

int Level::getReward() {
    return reward;
}

