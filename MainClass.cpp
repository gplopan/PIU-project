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
    bool success = QObject::connect(&start_game, &StartGame::sendClickData, &mainwindow, &MainWindow::AddTowerToMap);
    
  
    // qDebug() << "Debug"; => folosim qDebug() pentru debug "profesionist"
    mainwindow.mainwindow->show();
    return app.exec();
}

void QWidget::mousePressEvent(QMouseEvent* event)
{
    emit start_game.sendClickData(event->x(), event->y());
    start_game.sendClickData(event->x(), event->y());
}

