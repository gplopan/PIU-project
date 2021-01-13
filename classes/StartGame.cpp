//
// Created by ionut on 24.11.2020.
// Code written by ionut & georgiana
//

#include "headers/StartGame.h"
#include "headers/MainWindow.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <headers/Enemy.h>
#include <QTimer>

///constructor
StartGame::StartGame(QString qString) {
    if (qString.isEmpty())
        player = new Player();
    else
        player = new Player(qString.toStdString());
    level = new Level();
}

StartGame::~StartGame() {
    delete player;
    delete level;
}

void StartGame::emitToAddTower(int x, int y) {}

void StartGame::emitToRotateTower(int x, int y) {}

void StartGame::emitTurnToEnemy(int x, int y) {}

int StartGame::GetAction(int x, int y) {
    return this->level->GetAction(x, y);
}

///signal that tells the mainwindow to draw an enemy object
//todo figure how the timer works. should code be before the start or in a separate function?
void StartGame::generateWave() {
    QTimer *timer = new QTimer();
    timer->start(1500);
//    for (int i = 0; i < level->getNextEnemies(level->getWave()); i++) {
//        timer->callOnTimeout(this->drawEnemyInScene());
//    }
    drawEnemyInScene();
    //for more than 1 wave? call on nextwave somehow
}



///slot that returns the value of the tile at (x,y)
void StartGame::getTile(int * tile,int x, int y) {
    *tile=level->getPath(y,x);
}

void StartGame::impulse() {
    for (int i = 0; i < level->getNextEnemies(level->getWave()); i++) {
        drawEnemyInScene();
    }
}




