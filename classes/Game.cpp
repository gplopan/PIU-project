//
// Created by georgiana on 24.11.2020.
//

#include "headers/Game.h"
#include "headers/MainWindow.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

///constructor
Game::Game(QWidget *parent) {
    this->setFixedSize(200, 100);
    nameEdit = new QLineEdit("Player", parent = this);
    nameEdit->setAlignment(Qt::AlignLeft);
    nameEdit->setMaxLength(20);
    qPushButton = new QPushButton("START",parent = this);
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
//        QLabel *label = new QLabel(QString::fromStdString(player->getName()), this);
//        label->show();
        delete nameEdit;
        delete qPushButton;
//        delete this->window();
        this->window()->hide();
        level= new Level();
        mainW= new MainWindow();
        mainW->SetData();
        mainW->mainwindow->show();
    }
}



