//
// Created by georgiana on 24.11.2020.
//

#include "headers/Game.h"
#include "headers/MainWindow.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <headers/Enemy.h>
#include <QTimer>

///constructor
Game::Game(QWidget *parent) {
    this->setFixedSize(200, 100);
    nameEdit = new QLineEdit("Player", parent = this);
    nameEdit->setAlignment(Qt::AlignLeft);
    nameEdit->setMaxLength(20);
    qPushButton = new QPushButton("START", parent = this);
    qPushButton->setFixedSize(100, 50);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(nameEdit);
    layout->addWidget(qPushButton);
    this->setLayout(layout);
    QObject::connect(qPushButton, SIGNAL(clicked()), this, SLOT(start()));
}

Game::~Game() {
    delete player;
}

void Game::start() {
    if (nameEdit) {
        QString qString = nameEdit->text();
        if (qString.isEmpty())
            player = new Player();
        else
            player = new Player(qString.toStdString());
//        delete nameEdit;
//        delete qPushButton;
//        delete this->window();
        this->window()->hide();
        level = new Level();
        mainW = new MainWindow();
        mainW->SetData();
        mainW->mainwindow->show();
        ///todo figure this out
        QTimer *timer = new QTimer(this);

        for(int i=0;i<level->getNextEnemies(level->getWave());i++)
        {
            Enemy *enemy = new Enemy(1, 1, "enemy.png", mainW);
            enemy->setCoordinates(i,0);
            connect(timer, SIGNAL(timeout()), enemy, SLOT(reposition()));
            mainW->mainwindow->layout()->addWidget(enemy);
        }

        timer->start(1000);

    }
}



