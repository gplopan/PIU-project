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
private:
    int counter;
public:
    Player *player;
    Level *level;
    QTimer * generateTimer;
    StartGame();
	StartGame(QString qString);
	int GetAction(int x, int y);
	~StartGame();
	void reset(int level);

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

