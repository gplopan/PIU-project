//
// Created by georgiana on 26.11.2020.
//
#include <iostream>
#include <QtWidgets/QWidget>

#ifndef CLASSES_BULLET_H
#define CLASSES_BULLET_H

using namespace std;

class Bullet: public QWidget {
Q_OBJECT
private:
    int damagePower;
    string spriteName;
    int speed;
public:
    Bullet();
    Bullet(int d, string sprite, int s);
    //todo constructor de copiere
    ~Bullet(){};
    int getDamagePower();
    int getSpeed();
    string getFilename();
};


#endif //CLASSES_BULLET_H
