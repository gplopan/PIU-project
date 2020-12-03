//
// Created by ionut on 24.11.2020.
// Code written by ionut & georgiana
//
#include "../headers/Level.h"
#include "Player.h"
#include "../headers/Includes.h"

#ifndef CLASSES_STARTGAME_H
#define CLASSES_STARTGAME_H


// aici o sa ne jucam cu jocul
// am zis ca marimea unui sprite sa fie 70x70
class StartGame : public QObject
{
	Q_OBJECT
private:
	Player* player;
	Level level;
	QLineEdit* nameEdit;
	QPushButton* qPushButton;
	
	int clickX;
	int clickY;
	int vectorX;
	int vectorY;
	
	
public:
	StartGame();
	int GetAction(int x, int y);
	~StartGame();
	
	
signals:
	inline void emitToAddTower(int x, int y);
	inline void emitToRotateTower(int x, int y);
	inline void emitTurnToEnemy(int x, int y);

public slots:
	//void start();
};

#endif 