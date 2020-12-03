//
// Created by georgiana on 23.11.2020.
//

#include "../headers/Enemy.h"

///constructor of enemy class with specific atributes
Enemy::Enemy(int h, int s, std::string sprite, QWidget* parent) {
    this->health = h;
    this->speed = s;
    sprintName = sprite;
    this->setParent(parent);
    std::string path = "/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/";
    QPixmap pix(QString::fromStdString(path.append(sprintName)));
    this->setPixmap(pix.scaled(70, 70, Qt::KeepAspectRatio));
}

///level 1 -> general type of enemy
///will require alterations on values along the way
Enemy::Enemy() {
    health = 2;
    speed = 1;
    QPixmap pix("/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/enemy.png");
    int w = 100;
    int h = 100;
    this->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

///lower the health of the enemy
void Enemy::TakeDamage(int damage) {
    health -= damage;
    if (health <= 0)
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

///x coordinate of the enemy
int Enemy::getX() {
    return x;
}

/// y coordinate of the enemy
int Enemy::getY() {
    return y;
}


//todo further tests will have to be implemented
///move the enemy to the (nx,ny) coordinates
void Enemy::walk(int nx, int ny) {
    this->setGeometry(QRect(nx, ny, 100, 100));
    x += nx;
    y += ny;
}

/// set the (x, y). not recommended except for the init stage of the level
void Enemy::setCoordinates(int x, int y) {
    this->x = x;
    this->y = y;
    this->setGeometry(QRect(y * 70, x * 70 - 20, 70, 70));
}

///slot function. moves the enemy graphically
void Enemy::reposition() {
    //    walk(10,0);
    setCoordinates(x, y + 1);
}

///returns the name of the sprite. does not include the path to the root directory
std::string Enemy::getFilename() {
    return sprintName;
}


