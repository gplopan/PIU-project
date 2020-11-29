//
// Created by georgiana on 24.11.2020.
//

#ifndef CLASSES_GAME_H
#define CLASSES_GAME_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include "Player.h"
#include "Level.h"
#include "MainWindow.h"

///ma gandesc ca cel mai bine ar fi sa mosteneasca widget ca sa putem tine all the bullshit here
class Game : public QWidget {
Q_OBJECT
private:
    Player *player;
    Level * level;
    QLineEdit * nameEdit;
    QPushButton *qPushButton;
    MainWindow * mainW;
public:
    Game(QWidget *parent = nullptr);
    ~Game();

public slots:
    void start();
};


#endif //CLASSES_GAME_H

