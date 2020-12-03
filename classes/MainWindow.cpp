#include "../headers/MainWindow.h"
#include "../headers/Includes.h"

MainWindow::~MainWindow() {
    delete gameScene;
}

MainWindow::MainWindow() : QGraphicsView(),QGraphicsScene(), gameScene(new QGraphicsScene), gameView(new QGraphicsView)
{
	QObject::connect(&start_game, &StartGame::emitToAddTower, this, &MainWindow::AddTowerToMap);
	QObject::connect(&start_game, &StartGame::emitTurnToEnemy, this, &MainWindow::RotateTowardsEnemy);
	
}
/// <summary>
/// functia ce va adauga un turn pe harta in functie de selectia player-ului (momentan adauga un turn pe harta la click, daca in locatia respectiva
/// se poate adauga un turn (nu este drum sau nu exista obiecte pe care nu s-ar putea construi (piatra/copac etc))
/// </summary>
void MainWindow::AddTowerToMap(int x, int y)
{
	qDebug() << "mesaj = " << x/70 << " , " << y/70;
	qDebug() << "add tower";
	//calculam pozitia sa punem turnul fix pe tile
	int pozX = x / 70;
	int pozY = y / 70;

	towers.append(Tower(pozX, pozY));
	
	QPixmap tower("./images/tower1p4.png");
	QGraphicsItem* item = new QGraphicsPixmapItem(tower);
	item->setPos(pozX * 70, pozY * 70);
	gameScene->addItem(item);
	
	

}

void MainWindow::SetData()
{
	gameScene = new QGraphicsScene(0, 25, 1260, 784);
	this->gameScene->installEventFilter(this);
	QPixmap imagename("./images/level2.png");
	gameScene->addPixmap(imagename);

	
	gameView->setScene(gameScene);
	gameView->setFixedSize(1260, 924);
	
	///create toolbar and toolbutton w/ icon
	QToolBar* qToolBar = new QToolBar();
	QToolButton* qToolButton = new QToolButton();
	QIcon icon("./images/tower1p1.png");
	qToolButton->setIcon(icon);
	

	///add button to bar
	qToolBar->addWidget(qToolButton);
	///make bar movable - fix for not knowing how to move it
	qToolBar->setMovable(true);
	///set the icon size to the size of the button
	qToolBar->setIconSize(QSize(qToolButton->size().width(), qToolButton->size().height()));


	///// TODO legat de ce a facut ionut cu butonul din toolbar. cumva butonul trebuie sa activeze un singur click pentru
	///// plasarea unui tower si dupa sa trebuiasca apasat iar SAU sa fie valabil pana la dezactivare
	qToolBar->setFixedSize(1260, 80);
	QGraphicsProxyWidget* item = gameScene->addWidget(qToolBar);
	item->setPos(0, 784);
	item->setZValue(1);
	///860 -> 790 am ecran mic si mi se pare ca imaginea loops oricum in partea de jos la 860 cu noile rezolutii
	gameView->show();
	
	
}

/// <summary>
/// functia care va stabili enemy-ul in care va trage turnul (momentan este facuta ca turnul sa focuseze o pozitia data de click pe drum)
/// </summary>
void MainWindow::RotateTowardsEnemy(int x, int y)
{
	int range = 2;
	for(int rangeX=-70;rangeX<=70;rangeX+=70)
		for(int rangeY=-70;rangeY<=70;rangeY+=70)
		{
			for(int i=0; i<towers.count();i++)
			{
				if(towers[i].getX() == (x+rangeX)/70 && towers[i].getY() == (y+rangeY)/70)
				{
					qDebug() << "schimbam turn dupa click";
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
			return "./images/tower1p7.png";
		else
			return "./images/tower1p3.png";
	}
	else if(tx == ex)
	{
		if (ty > ey)
			return "./images/tower1p1.png";
		else
			return "./images/tower1p5.png";
	}
	else if(ty > ey)
	{
		if(tx > ex)
			return "./images/tower1p8.png";
		else
			return "./images/tower1p2.png";
	}
	else if(ty < ey)
	{
		if(tx < ex)
			return "./images/tower1p4.png";
		else
			return "./images/tower1p6.png";
	}
}

bool MainWindow::eventFilter(QObject* watched, QEvent* event)
{
	if (watched == gameScene) {
		QGraphicsSceneMouseEvent* mouseSceneEvent;
		if (event->type() == QEvent::GraphicsSceneMousePress) {
			mouseSceneEvent = static_cast<QGraphicsSceneMouseEvent*>(event);
			qDebug() << " x = " << mouseSceneEvent->scenePos().x() << " y = " << mouseSceneEvent->scenePos().y();
			int pozX = mouseSceneEvent->scenePos().x();
			int pozY = mouseSceneEvent->scenePos().y();

			if (pozX / 70 < 18 && pozY / 70 < 11) {
				int _action = this->start_game.GetAction(pozX, pozY);
				qDebug() << " action= " << _action;
				switch (_action)
				{
				case 0:
					// se poate construi turn
					emit this->start_game.emitToAddTower(pozX, pozY);
					break;
				case 5:
					// exista turn

					break;
				case 1:
					// este pe drum
					emit this->start_game.emitTurnToEnemy(pozX, pozY);
					break;
				case 2:
					// este pe colt (va fi schimbat probabil)
					emit this->start_game.emitTurnToEnemy(pozX, pozY);
					break;

				default:
					break;
				}
			}
		}
		
	}
	return QGraphicsView::eventFilter(watched, event);
}
/*
void QGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{

	
	}
}*/