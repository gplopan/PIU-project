//
// Created by georgiana on 24.11.2020.
//

#ifndef CLASSES_TOWER_H
#define CLASSES_TOWER_H


class Tower {
private:
    //int health;
    int power;
    int reloadTime;
    int cost;
    int x;
    int y;
public:
    Tower(int x, int y);
    Tower(int p, int rt, int c, int x, int y);
    ~Tower() {}
    //void takeDamage(int damage);
    void shoot();
    int getPower();
    int getTime();
    int getX();
    int getY();
};


#endif //CLASSES_TOWER_H
