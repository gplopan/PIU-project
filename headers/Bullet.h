//
// Created by georgiana on 26.11.2020.
//
#include <iostream>
#include <QtWidgets/QWidget>
#include "../headers/Includes.h"
#ifndef CLASSES_BULLET_H
#define CLASSES_BULLET_H

using namespace std;

class Bullet: public QWidget, public QGraphicsPixmapItem {
Q_OBJECT
private:
    int damagePower;
    string spriteName;
    int speed;
    int bulletX, bulletY;
    int enemyX, enemyY;
    int towerX, towerY;
    QTimer* bulletTime;
    int bullettime;
    int currentX, currentY;
    int stoppingPoint;
public:
    Bullet();
    Bullet(int d, string sprite, int s);
    ~Bullet();
    void towerPos(int x, int y);
    int getDamagePower();
    int getSpeed();
    string getFilename();
    void advance();

signals:
    inline void enemyDamaged(int x, int y);
	
	
public slots:
    void getTargetLocation(int x, int y);
};


#endif //CLASSES_BULLET_H
