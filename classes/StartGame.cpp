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
{}

bool StartGame::CanBuild(int x, int y)
{
	int** _board = board.getBoard();
	int pozX = x / 70;
	int pozY = y / 70;
	
	if (_board[pozY][pozX] == 0)
		return true;
	return false;
}


