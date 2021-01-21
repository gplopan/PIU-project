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
    int lastSavedScore; //score used for resetting the level
    int defaultResources; // a default amount of gold - used at resetting a level
                          // will only change when it's more than the previous value aka when receiving a reward after a level
public:
    Player();
    Player(string n);
    ~Player()= default;
    string getName();
    int getResources();
    void updateResources(int r);
    int getScore();
    void updateScore(int s);
    void updateSavedScore();
    void resetPlayer();
};


#endif //CLASSES_PLAYER_H
