//
// Created by ionut on 24.11.2020.
// Code written by ionut & georgiana
//


#include "headers/StartGame.h"
#include "headers/Includes.h"

void StartGame::sendClickData(int x, int y)
{
	this->clickX = x;
	this->clickY = y;

	this->vectorX = x / 25;
	this->vectorY = y / 25;

	qDebug() << "click x = " << x << " si click y = " << y;
	qDebug() << "vector x = " << this->vectorX << " si vector y = " << this->vectorY;
}
