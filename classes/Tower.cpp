//
// Created by georgiana on 24.11.2020.
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

///will be replaced with initializing from a file maybe
//Tower::Tower(int p, int rt, int c, int range, string sprite,QWidget * parent) {
Tower::Tower(int p, int rt, int c, int range) {
    power=p;
    reloadTime=rt;
    cost=c;
    this->range=range;
//    spriteName=sprite;
//    std::string path="/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/";
//    QPixmap pix(QString::fromStdString(path.append(spriteName)));
//    this->setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio));
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

///get x coordinate
int Tower::getX() {
    return x;
}

///get y coordinate
int Tower::getY() {
    return y;
}

///get the range of the tower
int Tower::getRange()
{
    return range;
}

int Tower::getCost() {
    return cost;
}
