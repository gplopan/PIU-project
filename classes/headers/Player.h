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
public:
    Player();
    Player(string n);
    ~Player()= default;
    string getName();
    int getResources();
    void updateResources(int r);
    int getScore();
    void updateScore(int s);
};


#endif //CLASSES_PLAYER_H
