//
// Created by ionut on 24.11.2020.
//


#include "headers/Board.h"

Board::Board(int level) {
	this->level = level;
	this->board = new int* [54];
	for (int i = 0;i < 36;i++)
		this->board[i] = new int[36];
}

int** Board::getBoard()
{
	return this->board;
}

int Board::getLevel()
{
	return this->level;
}



