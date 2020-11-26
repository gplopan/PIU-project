//
// Created by ionut on 24.11.2020.
// Code written by ionut & georgiana
//
#include "../headers/Board.h"
#include "../headers/Includes.h"

#ifndef CLASSES_STARTGAME_H
#define CLASSES_STARTGAME_H


// aici o sa ne jucam cu jocul
// am zis ca marimea unui sprite sa fie 40x40
class StartGame : public QObject
{
	Q_OBJECT
	int clickX;
	int clickY;
	int vectorX;
	int vectorY;

public:
	Board board;
	StartGame();
	
public slots:
	void sendClickData(int x, int y);
signals:
	inline void sendCoordonates(const QString& text);
	
};

#endif 