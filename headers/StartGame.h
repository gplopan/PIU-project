//
// Created by ionut on 24.11.2020.
// Code written by ionut & georgiana
//
//
#ifndef CLASSES_STARTGAME_H
#define CLASSES_STARTGAME_H

// aici o sa ne jucam cu jocul
// am zis ca marimea unui sprite sa fie 25x25
class StartGame
{
private:
	int clickX;
	int clickY;
	int vectorX;
	int vectorY;
public:
	void sendClickData(int x, int y);
};

#endif 