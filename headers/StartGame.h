//
// Created by ionut on 24.11.2020.
// Code written by ionut & georgiana
//
//
#ifndef CLASSES_STARTGAME_H
#define CLASSES_STARTGAME_H
#include "headers/Board.h"
#include "headers/Includes.h"
// aici o sa ne jucam cu jocul
// am zis ca marimea unui sprite sa fie 40x40
class StartGame
{
private:
	int clickX;
	int clickY;
	int vectorX;
	int vectorY;

public:
	Board board;
	
	StartGame();
	void sendClickData(int x, int y);
};

#endif 