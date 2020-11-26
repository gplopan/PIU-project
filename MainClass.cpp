#include "headers/MainWindow.h"
#include "headers/Includes.h"
#include "headers/StartGame.h"

StartGame start_game;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MainWindow mainwindow;
    QDesktopWidget qdw;
    mainwindow.SetData();
    //
   
	
	// connections 
    QObject::connect(&start_game, &StartGame::sendCoordonates, &mainwindow, &MainWindow::AddTowerToMap);
	
  
    // qDebug() << "Debug"; => folosim qDebug() pentru debug "profesionist"
    mainwindow.mainwindow->show();
    return app.exec();
}

void QWidget::mousePressEvent(QMouseEvent* event)
{
    start_game.sendClickData(event->x(), event->y());
}

