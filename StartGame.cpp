//
// Created by ionut on 24.11.2020.
// Code written by ionut & georgiana
//


#include "headers/StartGame.h"
#include "headers/Includes.h"

StartGame::StartGame()
{
	this->board = Board(1);
	this->board.setBoard(1);
}



void StartGame::sendClickData(int x, int y)
{
	this->clickX = x;
	this->clickY = y;

	this->vectorX = x / 40;
	this->vectorY = y / 40;

	qDebug() << "click x = " << x << " si click y = " << y;
	qDebug() << "vector x = " << this->vectorX << " si vector y = " << this->vectorY;
}
