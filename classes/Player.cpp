//
// Created by georgiana on 24.11.2020.
//

#include "headers/Player.h"

///constructor. n will be provided through the gui. basic values apply
Player::Player(string n) {
    name=n;
    score=0;
    resources=10;
}

///get name of the player
string Player::getName() {
    return name;
}

///get resources
int Player::getResources() {
    return resources;
}

///add r to the resources
void Player::updateResources(int r) {
    resources+=r;
}


///get score
int Player::getScore() {
    return score;
}

///add s to the current score of the player
void Player::updateScore(int s) {
    score+=s;
}


///generic player 'account'
Player::Player() {
    name="Player";
    score=0;
    resources=10;
}




