//
// Created by georgiana on 24.11.2020.
//

#ifndef CLASSES_PLAYER_H
#define CLASSES_PLAYER_H
#include <iostream>

using namespace std;

class Player {
private:
    string name;   // name of the player
    int score;     // points gathered
    int resources; // amount of gold left
    int currentLevel; // current level of the game
public:
    Player(string n);
    ~Player();
    string getName();
    int getResources();
    void setResources(int r);
    int getLevel();
    void setLevel(int l);
    int getScore();
    void setScore(int s);

};


#endif //CLASSES_PLAYER_H
