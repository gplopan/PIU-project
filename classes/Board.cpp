//
// Created by ionut on 24.11.2020.
//
#include "headers/Board.h"

#include <iostream>
#include <fstream>

using namespace std;

Board::Board() {
	this->board = new int* [11];
	for (int i = 0;i < 11;i++)
		this->board[i] = new int[18];

	for (int i = 0;i < 11;i++)
	{
		for (int j = 0;j < 18;j++)
			board[i][j] = 0;
	}

}

int** Board::getBoard()
{
	return this->board;
}

Board::~Board()
{
    delete[] board;
}


void Board::setBoard(int mapLevel)
{
//	string filename = "maps/map" + to_string(mapLevel) + ".txt";
    string filename = "/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/levels/map" + to_string(mapLevel) + ".txt";
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

///uses x and y as out variables for the coordinates in the matrix for the spawing point of the enemies
void Board::getStartPoint(int *x, int *y) {
    for(int a=0;a<18;a++)
        for(int b=0;b<11;b++) {
            if (board[b][a] == 3) {
                *x = a;
                *y = b;
                break;
            }
        }
}




