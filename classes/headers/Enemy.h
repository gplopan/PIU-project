//
// Created by georgiana on 23.11.2020.
//
#include <iostream>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QMouseEvent>

#ifndef CLASSES_ENEMY_H
#define CLASSES_ENEMY_H


class Enemy: public QLabel {
Q_OBJECT
private:
    int health;
    int speed;
    //bool alive=true;
    int x,y;
    std::string sprintName;
public:
    Enemy();
    Enemy(int h, int s, std::string sprint, QWidget * parent= nullptr);
    ~Enemy()= default;
    int getHealth();
    int getX();
    int getY();
    std::string getFilename();
    void setCoordinates(int x, int y);
    void TakeDamage(int damage);
    void walk(int nx, int ny);
    void die();
public slots:
    void reposition();
};


#endif //CLASSES_ENEMY_H
