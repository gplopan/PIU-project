//
// Created by ionut on 24.11.2020.
// Code written by ionut & georgiana
//

#ifndef CLASSES_STARTGAME_H
#define CLASSES_STARTGAME_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include "Player.h"
#include "Level.h"

class StartGame : public QObject {
Q_OBJECT
public:
    Player *player;
    Level *level;
    StartGame();
	StartGame(QString qString);
	int GetAction(int x, int y);
	~StartGame();
	void impulse();

signals:
	inline void emitToAddTower(int x, int y);
	inline void emitToRotateTower(int x, int y);
	inline void emitTurnToEnemy(int x, int y);
	inline void drawEnemyInScene();

public slots:
    void getTile(int * tile,int x, int y);
    void generateWave();
};


#endif //CLASSES_STARTGAME_H

