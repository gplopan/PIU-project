//
// Created by georgiana on 24.11.2020.
//

#include <iostream>
#include <QtWidgets/QLabel>

#ifndef CLASSES_TOWER_H
#define CLASSES_TOWER_H

using namespace std;

class Tower: public QLabel {
Q_OBJECT
private:
    int power;
    int reloadTime;
    int cost;
    int x;
    int y;
    int range;
    string spriteName;
    // Bullet * bullet;
public:
    Tower(int x, int y);
    Tower(int p, int rt, int c, int range,string sprite,QWidget * parent=nullptr);
    ~Tower() {}
    void shoot();
    int getPower();
    int getTime();
    int getX();
    int getY();
};


#endif //CLASSES_TOWER_H
