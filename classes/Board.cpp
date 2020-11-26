//
// Created by ionut on 24.11.2020.
//
#include "../headers/Includes.h";
#include "../headers/Board.h"

#include <iostream>

using namespace std;

Board::Board(int level) {
	this->level = level;
	this->board = new int* [11];
	for (int i = 0;i < 11;i++)
		this->board[i] = new int[18];

	for (int i = 0;i < 11;i++)
	{
		for (int j = 0;j < 18;j++)
			board[i][j] = 0;
	}
	
}

Board::Board()
{}

int** Board::getBoard()
{
	return this->board;
}

int Board::getLevel()
{
	return this->level;
}

void Board::setBoard(int mapLevel)
{
	string filename = "maps/map" + to_string(mapLevel) + ".txt";
	ifstream infile;
	infile.open(filename.c_str());
	if (infile.is_open()) {
		for (int i = 0;i < 11;i++)
		{
			for (int j = 0;j < 18;j++)
			{
				int valoare = 0;
				infile >> valoare;
				this->board[i][j] = valoare;
			}
		}
	}
	
}



