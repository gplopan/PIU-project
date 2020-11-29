#include "headers/MainWindow.h"
#include "headers/Includes.h"
#include "headers/StartGame.h"

StartGame start_game;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MainWindow gameScene;
    gameScene.gameScene = new QGraphicsScene(0, 0, 1260, 784);
	
    QGraphicsView viewwindow;

	
	// connections
    QObject::connect(&start_game, &StartGame::emitToAddTower, &gameScene, &MainWindow::AddTowerToMap);
    QObject::connect(&start_game, &StartGame::emitTurnToEnemy, &gameScene, &MainWindow::RotateTowardsEnemy);
    // qDebug() << "Debug"; => folosim qDebug() pentru debug "profesionist"

	QPixmap imagename("./images/level2.png");
    gameScene.gameScene->addPixmap(imagename);
    viewwindow.setScene(gameScene.gameScene);
    
    viewwindow.setFixedSize(1260, 864);
	viewwindow.show();
    return app.exec();
}
//  virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
void QGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    qDebug() << " x = " << event->scenePos().x() << " y = " << event->scenePos().y();
    int pozX = event->scenePos().x();
    int pozY = event->scenePos().y();

    int _action = start_game.GetAction(pozX, pozY);
    qDebug() << " action= " << _action;
	switch(_action)
	{
    case 0:
		// se poate construi turn
        emit start_game.emitToAddTower(pozX, pozY);
        break;
    case 5:
		// exista turn
        
        break;
    case 1:
		// este pe drum
        emit start_game.emitTurnToEnemy(pozX, pozY);
        break;
    case 2:
        // este pe colt (va fi schimbat probabil)
        emit start_game.emitTurnToEnemy(pozX, pozY);
        break;

    default:
        break;
	}
}


