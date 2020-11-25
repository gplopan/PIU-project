//
// Created by georgiana on 23.11.2020.
//

#include "headers/Enemy.h"

//todo niste enum-uri sau ceva pentru diferite clase de inamici ca sa fie mai usor de creat? sau cu citire din fisier
///constructor of enemy class with specific atributes
Enemy::Enemy(int h, int s, std::string sprint,QWidget * parent) {
    this->health=h;
    this->speed=s;
    sprintName=sprint;
    this->setParent(parent);
}

///level 1 -> general type of enemy
///will require alterations on values along the way
Enemy::Enemy() {
    health=2;
    speed=1;
}

///lower the health of the enemy
void Enemy::TakeDamage(int damage) {
    health-=damage;
    if(health<=0)
        die();
}

///getter for the health attribute
int Enemy::getHealth() {
    return health;
}

//todo
///ar trebui sa arate ca nu mai trebuie randat pe harta? idk
///sets alive flag on false. enemy ready to be destroyed
void Enemy::die() {
    //alive=false
}

int Enemy::getX() {
    return x;
}

int Enemy::getY() {
    return y;
}

///move the enemy to the (nx,ny) coordinates
//void Enemy::move(int nx, int ny) {
//    x=nx;
//    y=ny;
//    ///todo further tests will have to be implemented
//}

void Enemy::setCoordinates(int x, int y) {
    this->x=x;
    this->y=y;
}

void Enemy::reposition() {
    this->setGeometry(QRect(300,200,100,100));
}

//void Enemy::reposition(QMouseEvent *event) {
//    this->setGeometry(QRect(0,0,event->pos().x(),event->pos().y()));
//}


