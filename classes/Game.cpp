//
// Created by georgiana on 24.11.2020.
//

#include "headers/Game.h"
#include <QKeyEvent>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>

///constructor
Game::Game(QWidget *parent) {
    QLineEdit * nameEdit = new  QLineEdit("Player");
    nameEdit->setAlignment(Qt::AlignLeft);
    nameEdit->setMaxLength(20);

    QFont font = nameEdit->font();
//    font.setPointSize(font.pointSize() + 8);
    nameEdit->setFont(font);

    QPushButton *startButton = new QPushButton  (tr("Start Game"));//, SLOT(equalClicked()));
    QHBoxLayout* layout = new   QHBoxLayout;
    layout->addWidget(nameEdit);
    layout->addWidget(startButton);
    this->setLayout(layout);

    player = new Player("ana");
    
}

Game::~Game() {
    delete player;
}



