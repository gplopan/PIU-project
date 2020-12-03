//
// Created by ionut on 24.11.2020.
// Code written by ionut & georgiana
//


#include "../headers/StartGame.h"
#include "../headers/Includes.h"
#include "../headers/MainWindow.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include "../headers/Enemy.h"
#include <QTimer>
#include "../headers/Board.h"

StartGame::StartGame() : QObject()
{
	
	//this->level = new Level();
	// plopi
	/*
	this->setFixedSize(200, 100);
	nameEdit = new QLineEdit("Player", this);
	nameEdit->setAlignment(Qt::AlignLeft);
	nameEdit->setMaxLength(20);
	qPushButton = new QPushButton("START", this);
	qPushButton->setFixedSize(100, 50);
	QHBoxLayout* layout = new QHBoxLayout;
	layout->addWidget(nameEdit);
	layout->addWidget(qPushButton);
	this->setLayout(layout);
	*/
	//QObject::connect(qPushButton, SIGNAL(clicked()), this, SLOT(start()));
}


StartGame::~StartGame() {
	delete player;
}

void StartGame::emitToAddTower(int x, int y)
{}
void StartGame::emitToRotateTower(int x, int y)
{}
void StartGame::emitTurnToEnemy(int x, int y)
{}



int StartGame::GetAction(int x, int y)
{
	return this->level.GetAction(x, y);
}



// cand apesi start
/*
void StartGame::start() {
	if (nameEdit) {
		QString qString = nameEdit->text();
		if (qString.isEmpty())
			player = new Player();
		else
			player = new Player(qString.toStdString());
		//        delete nameEdit;
		//        delete qPushButton;
		//        delete this->window();
		this->window()->hide();
		level = new Level();
		mainW = new MainWindow();
		mainW->SetData();
		mainW->mainwindow->show();
		//todo figure this out
		QTimer* timer = new QTimer(this);

		for (int i = 0;i < level->getNextEnemies(level->getWave());i++)
		{
			Enemy* enemy = new Enemy(1, 1, "enemy.png", mainW);
			enemy->setCoordinates(i, 0);
			connect(timer, SIGNAL(timeout()), enemy, SLOT(reposition()));
			mainW->mainwindow->layout()->addWidget(enemy);
		}

		timer->start(1000);

	}
}
*
* 
 */
