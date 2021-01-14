#include "headers/MainWindow.h"
#include <QLayout>
#include <QGraphicsSceneMouseEvent>
#include <QEvent>
#include <QTimer>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QGraphicsProxyWidget>
#include <headers/Enemy.h>


MainWindow::~MainWindow() {
    delete gameScene;
}

MainWindow::MainWindow()
{
    start_game=nullptr;
    gameScene=new QGraphicsScene();
    gameView=new QGraphicsView(gameScene);
}

/// <summary>
/// functia ce va adauga un turn pe harta in functie de selectia player-ului (momentan adauga un turn pe harta la click, daca in locatia respectiva
/// se poate adauga un turn (nu este drum sau nu exista obiecte pe care nu s-ar putea construi (piatra/copac etc))
/// </summary>
void MainWindow::AddTowerToMap(int x, int y)
{
//	qDebug() << "mesaj = " << x/70 << " , " << y/70;
//	qDebug() << "add tower";
	//calculam pozitia sa punem turnul fix pe tile
	int pozX = x / 70;
	int pozY = y / 70;
	Tower towerobj(pozX,pozY);
    if(start_game->player->getResources()-towerobj.getCost()>0) {
        towers.append(Tower(pozX, pozY));
        QPixmap tower("/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/tower1p4.png");
        QGraphicsItem *item = new QGraphicsPixmapItem(tower);
        item->setPos(pozX * 70, pozY * 70);
        gameScene->addItem(item);
        start_game->player->updateResources(towerobj.getCost());
    }
}

///used for the preparing the graphic scene and graphic view
void MainWindow::SetData(int level)
{
	gameScene = new QGraphicsScene(0, 0, 1260, 780);
	gameScene->installEventFilter(this);
	string levelname="/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/level"+to_string(level)+".png";
	QPixmap imagename(QString::fromStdString(levelname));
//    gameScene->setBackgroundBrush(QBrush(imagename));
    gameScene->addPixmap(imagename);


	gameView->setFixedSize(1260, 780);
    gameView->setSceneRect(0, 0, 1260, 780);
    gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//create toolbar and toolbutton w/ icon
	QToolBar* qToolBar = new QToolBar();
	QToolButton* qToolButton = new QToolButton();
    QIcon icon("/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/tower1p1.png");
    qToolButton->setIcon(icon);
    qToolButton->setFixedSize(50,50);
	qToolBar->addWidget(qToolButton);
	qToolBar->setIconSize(QSize(qToolButton->size().width()+10, qToolButton->size().height()));


    QToolButton* resetButton = new QToolButton();
    QIcon icon2("/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/reset.png");
    resetButton->setIcon(icon2);
    resetButton->setFixedSize(50,50);
    qToolBar->addWidget(resetButton);
//    qToolBar->setIconSize(QSize(resetButton->size().width(), resetButton->size().height()));

    QObject::connect(resetButton, SIGNAL(clicked(bool)), this, SLOT(reset(bool)));


    QGraphicsProxyWidget* item = gameScene->addWidget(qToolBar);
	item->setPos(0, 730);
	item->setZValue(1);
	item->setFocus();

    //create text for user information
    string string1="Gold:  " + to_string(start_game->player->getResources())+" Score: " + to_string(start_game->player->getScore());
    string strin2="Level: "+to_string(start_game->level->getLevelNumber())+"   Wave: "+to_string(start_game->level->getWave());
    QGraphicsTextItem *playerInfo = gameScene->addText(QString(""));

    playerInfo->setHtml("<div style='background-color:#444745;'>" + QString::fromStdString(string1)+"<br>"+QString::fromStdString(strin2) + "</div>");
    playerInfo->setFont(QFont("TypeWriter", 17, QFont::Normal));
    playerInfo->setPos(1010,0);
    //todo this doesn't change at any point idk how to make it change

    gameView->setScene(gameScene);
	gameView->show();
}

/// <summary>
/// functia care va stabili enemy-ul in care va trage turnul (momentan este facuta ca turnul sa focuseze o pozitia data de click pe drum)
/// </summary>
void MainWindow::RotateTowardsEnemy(int x, int y)
{
	for(int rangeX=-70;rangeX<=70;rangeX+=70)
		for(int rangeY=-70;rangeY<=70;rangeY+=70)
		{
			for(int i=0; i<towers.count();i++)
			{
				if(towers[i].getX() == (x+rangeX)/70 && towers[i].getY() == (y+rangeY)/70)
				{
//					qDebug() << "schimbam turn dupa click";
					gameScene->removeItem(gameScene->itemAt(QPointF(x+rangeX, y+rangeY), QTransform()));

					int locX = x / 70;
					int locY = y / 70;
					QString filename = TowerPosition(towers[i].getX(), towers[i].getY(), locX, locY);
					QPixmap newTower(filename);
					QGraphicsItem* item = new QGraphicsPixmapItem(newTower);
					item->setPos(towers[i].getX() * 70, towers[i].getY() * 70);
					gameScene->addItem(item);
					towers.remove(i);
					towers.append(Tower((x+rangeX)/70, (y+rangeY)/70));
				}
			}
		}
}


/// <summary>
/// functie ce returneaza imaginea cu turnul focusat pe o anumita pozitie (ulterior pe pozitia inamicului)
/// </summary>
QString MainWindow::TowerPosition(int tx, int ty, int ex, int ey)
{
	// toate if-urile acestea vor fi schimbate ulterior cu un switch(angle)
	// angle va fi unghiul intre turn si enemy in functie de axa Ox
	if(ty == ey)
	{
		if (tx > ex)
			return "/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/tower1p7.png";
		else
			return "/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/tower1p3.png";

	}
	else if(tx == ex)
	{
		if (ty > ey)
			return "/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/tower1p1.png";
		else
			return "/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/tower1p5.png";
	}
	else if(ty > ey)
	{
		if(tx > ex)
			return "/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/tower1p8.png";
		else
			return "/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/tower1p2.png";
	}
	else if(ty < ey)
	{
		if(tx < ex)
			return "/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/tower1p4.png";
		else
			return "/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/tower1p6.png";
	}
}


bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
	if (watched == gameScene) {
		QGraphicsSceneMouseEvent* mouseSceneEvent;
		if (event->type() == QEvent::GraphicsSceneMousePress) {
			mouseSceneEvent = static_cast<QGraphicsSceneMouseEvent*>(event);
//			qDebug() << " x = " << mouseSceneEvent->scenePos().x() << " y = " << mouseSceneEvent->scenePos().y();
//			std::cout << " x = " << mouseSceneEvent->scenePos().x() << " y = " << mouseSceneEvent->scenePos().y();
			int pozX = mouseSceneEvent->scenePos().x();
			int pozY = mouseSceneEvent->scenePos().y();

			if (pozX / 70 < 18 && pozY / 70 < 11) {
				int _action = this->start_game->GetAction(pozX, pozY);
//				std::cout << " action= " << _action<<endl;
//				qDebug() << " action= " << _action;
				switch (_action)
				{
				case 0:
					// se poate construi turn
					emit this->start_game->emitToAddTower(pozX, pozY);
					break;
				case 1:
				case 6:
				case 7:
				case 8:
					// este pe drum
					emit this->start_game->emitTurnToEnemy(pozX, pozY);
					break;
				default:
					break;
				}
			}
		}

	}
	return QGraphicsView::eventFilter(watched, event);
//	return gameView(watched, event);
//	return true;
}

///signal
void MainWindow::beginLevel() {

}


///slot that is connected to the menu. to be used only for that initial call
void MainWindow::start(QString playerName)
{
    if(!start_game)
        start_game=new StartGame(playerName);   //create the start_game class with everything behind it
    else
        start_game->player->resetPlayer();
    SetData(start_game->level->getLevelNumber()); //prepare the graphic part of the game

    QObject::connect(start_game, SIGNAL(emitToAddTower(int, int)), this, SLOT(AddTowerToMap(int, int)));
    QObject::connect(start_game, &StartGame::emitTurnToEnemy, this, &MainWindow::RotateTowardsEnemy);

    QObject::connect(this, SIGNAL(beginLevel()), start_game, SLOT(generateWave()));
    QObject::connect(start_game, SIGNAL(drawEnemyInScene()), this, SLOT(drawEnemy()));

    beginLevel(); //signal the start game to start the enemy generation

    advanceTimer = new QTimer();
    //at every timeout the advance slot is called -- will generate advance signals towards all qgraphicsitems  in the scene
    QObject::connect(advanceTimer, SIGNAL(timeout()), gameScene, SLOT(advance()));
    advanceTimer->start(2000);

}

///slot: at every call a new enemy object is created and rendered
void MainWindow::drawEnemy() {
    auto* enemy=new Enemy();
    enemy->setCoordinates(start_game->level->startX,start_game->level->startY);

    enemy->setPos(mapToScene(enemy->getX()*70,enemy->getY()*70-10));
    QObject::connect(enemy, SIGNAL(getNextMovement(int *, int, int)), start_game, SLOT(getTile(int *, int, int)));
    QObject::connect(enemy, SIGNAL(won()), this, SLOT(lost()));
    gameScene->addItem(enemy); //add an enemy on the map
}

void MainWindow::lost() {
    advanceTimer->stop();
    std::cout<<"lost message"<<std::endl;
}

void MainWindow::updateInfo() {
}

void MainWindow::reset(bool reset) {
    std::cout<<"reset bi"<<std::endl;

    gameView->items().clear();
    gameScene->clearSelection();
    advanceTimer->stop();
    start_game->player->resetPlayer();
    towers.clear();
    SetData2(start_game->level->getLevelNumber());
    beginLevel();
    advanceTimer->start(2000);

}

void MainWindow::SetData2(int level) {
//    gameScene = new QGraphicsScene(0, 0, 1260, 780);
//    gameScene->installEventFilter(this);
    string levelname="/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/level"+to_string(level)+".png";
    QPixmap imagename(QString::fromStdString(levelname));
//    gameScene->setBackgroundBrush(QBrush(imagename));
    gameScene->addPixmap(imagename);

//
//    gameView->setFixedSize(1260, 780);
//    gameView->setSceneRect(0, 0, 1260, 780);
//    gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create toolbar and toolbutton w/ icon
    QToolBar* qToolBar = new QToolBar();
    QToolButton* qToolButton = new QToolButton();
    QIcon icon("/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/tower1p1.png");
    qToolButton->setIcon(icon);
    qToolButton->setFixedSize(50,50);
    qToolBar->addWidget(qToolButton);
    qToolBar->setIconSize(QSize(qToolButton->size().width()+10, qToolButton->size().height()));


    QToolButton* resetButton = new QToolButton();
    QIcon icon2("/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/reset.png");
    resetButton->setIcon(icon2);
    resetButton->setFixedSize(50,50);
    qToolBar->addWidget(resetButton);
//    qToolBar->setIconSize(QSize(resetButton->size().width(), resetButton->size().height()));

    QObject::connect(resetButton, SIGNAL(clicked(bool)), this, SLOT(reset(bool)));


    QGraphicsProxyWidget* item = gameScene->addWidget(qToolBar);
    item->setPos(0, 730);
    item->setZValue(1);
    item->setFocus();

    //create text for user information
    string string1="Gold:  " + to_string(start_game->player->getResources())+" Score: " + to_string(start_game->player->getScore());
    string strin2="Level: "+to_string(start_game->level->getLevelNumber())+"   Wave: "+to_string(start_game->level->getWave());
    QGraphicsTextItem *playerInfo = gameScene->addText(QString(""));

    playerInfo->setHtml("<div style='background-color:#444745;'>" + QString::fromStdString(string1)+"<br>"+QString::fromStdString(strin2) + "</div>");
    playerInfo->setFont(QFont("TypeWriter", 17, QFont::Normal));
    playerInfo->setPos(1010,0);
    //todo this doesn't change at any point idk how to make it change

//    gameView->setScene(gameScene);
//    gameView->show();
}





