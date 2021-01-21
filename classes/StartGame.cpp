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
//    level = new Level(4,3,3);
    generateTimer = new QTimer();
    QObject::connect(generateTimer,SIGNAL(timeout()),this,SLOT(generateWave()));
    QObject::connect(level,SIGNAL(finishedLevel()),this,SLOT(wait()));
    counter=0;
}

StartGame::~StartGame() {
    delete player;
    delete level;
    delete generateTimer;
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
    generateTimer->setInterval(2500);
    int enemy_nr_per_wave=level->getNextEnemies(level->getWave());
    if(enemy_nr_per_wave!=0)
    {
        if(counter<enemy_nr_per_wave)
        {
            counter++;
            drawEnemyInScene();
        }
        else
        {
            level->nextWave();
            counter=0;
            generateTimer->setInterval(7000);
        }
    }

}



///slot that returns the value of the tile at (x,y)
void StartGame::getTile(int * tile,int x, int y) {
    *tile=level->getPath(y,x);
}

void StartGame::reset(int level) {
    counter=0;
    player->resetPlayer();
    this->level->resetLevel(level);
}

///prepares the game for the next action. wait for the player to lose or win the level
void StartGame::wait() {
    generateTimer->stop();
    counter=0;

}





