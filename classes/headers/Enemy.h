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
    //todo make private name
public:
    std::string sprintName;
    Enemy();
    Enemy(int h, int s, std::string sprint, QWidget * parent= nullptr);
    ~Enemy()= default;
    int getHealth();
    int getX();
    int getY();
    void setCoordinates(int x, int y);
    void TakeDamage(int damage);
//    void move(int nx, int ny);
    void die();
public slots:
    void reposition();
//    void reposition(QMouseEvent * event);
};


#endif //CLASSES_ENEMY_H
