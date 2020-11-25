//
// Created by georgiana on 24.11.2020. Copyright.
//

#include "headers/Tower.h"

///level 1 - generic values for a generic tower
Tower::Tower(int x, int y) {
    power=1;
    reloadTime=2;
    cost=2;
    this->x=x;
    this->y=y;
}

Tower::Tower(int p, int rt, int c, int x, int y, int range) {
    power=p;
    reloadTime=rt;
    cost=c;
    this->x=x;
    this->y=y;
    this->range = range;
}

//todo
///not implemented
void Tower::shoot() {
    throw "Not implemented yet";
}

///get damage power
int Tower::getPower() {
    return power;
}

///get reload time
int Tower::getTime() {
    return reloadTime;
}

int Tower::getRange()
{
    return range;
}

///get x coordinate
int Tower::getX() {
    return x;
}

///get y coordinate
int Tower::getY() {
    return y;
}

