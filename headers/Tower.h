//
// Created by georgiana on 24.11.2020.
//

#include <iostream>
#include <QtWidgets/QLabel>
#include "../headers/Bullet.h"

#ifndef CLASSES_TOWER_H
#define CLASSES_TOWER_H

using namespace std;

class Tower : public QObject{
	Q_OBJECT
private:
    int power;
    int reloadTime;
    int cost;
    int x;
    int y;
    int range;
    
//    string spriteName;
   
public:
    Bullet* bullet;
    Tower(int x, int y);
//    Tower(int p, int rt, int c, int range,string sprite,QWidget * parent=nullptr);
    Tower(int p, int rt, int c, int range);
    ~Tower() {}
  
    void shoot();
    int getPower();
    int getTime();
    int getX();
    int getY();
    int getRange();
    int getCost();
signals:
    inline void sendBulletTarget(int x, int y);
   
public slots:
    void checkForEnemy(int x, int y);
};


#endif //CLASSES_TOWER_H
