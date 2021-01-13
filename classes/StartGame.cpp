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

void StartGame::generateWave() {

    ///todo figure this out
    QTimer *timer = new QTimer();
    for (int i = 0; i < level->getNextEnemies(level->getWave()); i++) {
        drawEnemyInScene();
    }
    timer->start(2000);
}




