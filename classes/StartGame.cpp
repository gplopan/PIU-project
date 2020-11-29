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



void StartGame::emitToAddTower(int x, int y)
{}
void StartGame::emitToRotateTower(int x, int y)
{}
void StartGame::emitTurnToEnemy(int x, int y)
{}

int StartGame::GetAction(int x, int y)
{
	
	int** _board = board.getBoard();
	int pozX = x / 70;
	int pozY = y / 70;

	int data = _board[pozY][pozX];

	if (data == 0)
		_board[pozY][pozX] = 5;
	return data;
}

int StartGame::RotateTower(int x, int y)
{
	
	int** _board = board.getBoard();
	int pozX = x / 70;
	int pozY = y / 70;

	if(_board[pozY][pozX] == 5)
	{
		return x * y;
	}
	return -1;
}



