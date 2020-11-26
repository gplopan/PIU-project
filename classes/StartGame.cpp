//
// Created by ionut on 24.11.2020.
// Code written by ionut & georgiana
//


#include "../headers/StartGame.h"
#include "../headers/Includes.h"

StartGame::StartGame() : QObject()
{
	this->board = Board(1);
	this->board.setBoard(1);
}



void StartGame::sendClickData(int x, int y)
{
}

