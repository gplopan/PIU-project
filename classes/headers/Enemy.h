//
// Created by georgiana on 23.11.2020.
//
#include <iostream>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QGraphicsItem>

#ifndef CLASSES_ENEMY_H
#define CLASSES_ENEMY_H


class Enemy: public QObject, public QGraphicsPixmapItem {
Q_OBJECT
private:
    int health;
    int speed;
    int posx, posy;
    int sprintCount;
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
signals:
    inline void getNextMovement(int *tile, int x, int y);
    inline void won();
public slots:
    void advance(int phase) override;
};


#endif //CLASSES_ENEMY_H
