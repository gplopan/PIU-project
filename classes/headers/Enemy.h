//
// Created by georgiana on 23.11.2020.
//
#include <iostream>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QGraphicsItem>

#ifndef CLASSES_ENEMY_H
#define CLASSES_ENEMY_H


class Enemy: public QGraphicsPixmapItem {
//Q_OBJECT
private:
    int health;
    int speed;
    //bool alive=true;
    int x,y;
    std::string sprintName;

public:
    Enemy();
    Enemy(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);
    Enemy(int h, int s, std::string sprint);
    ~Enemy(){};
    int getHealth();
    int getX();
    int getY();
    std::string getFilename();
    void setCoordinates(int x, int y);
    void TakeDamage(int damage);
    void die();

protected:
//    void advance(int step) override;

};


#endif //CLASSES_ENEMY_H
