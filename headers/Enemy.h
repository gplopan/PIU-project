//
// Created by georgiana on 23.11.2020.
//

#ifndef CLASSES_ENEMY_H
#define CLASSES_ENEMY_H


class Enemy {
private:
    int health;
    int speed;
    //bool alive=true;
    //int x,y
public:
    Enemy();
    Enemy(int h, int s);
    ~Enemy()= default;;
    int getHealth();
    void TakeDamage(int damage);
    //void move(int nx, int ny);
    void die();
};


#endif //CLASSES_ENEMY_H
