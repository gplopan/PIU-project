#include "headers/Includes.h"
#include "headers/Functions.h"
#include "headers/StartGame.h"

StartGame start_game;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QMainWindow mainwindow;
    QDesktopWidget qdw;
 
    // setting the image
    QWidget* image = new QWidget;
    image->setGeometry(0, 0, 1350, 800);
    image->setStyleSheet("background-image: url('./images/level2.jpg');");
    mainwindow.layout()->addWidget(image);
	
	//**** va trebui ca menu-ul de jos sa-l setam ca setstatus in mainwindow (vezi documentatia oficiala)
    mainwindow.setFixedSize(1350, 900);


	// qDebug() << "Debug"; => folosim qDebug() pentru debug "profesionist"
    
	
	mainwindow.show();

   /*
    * matricea => 0 toata
    * drum => 1
    * turnuri => 2
    * inamicii => 1 => merge => !1 => nu merge => 
    * final => 10
    * if inamici.location => final.x.y ( x/ceva y/ceva i,j=10 ? terminat)
    *
    *
	*
    */

    //insert event related instructions after this
    
    
    
    // start the window 
   
    return app.exec();
}

void QWidget::mousePressEvent(QMouseEvent* event)
{
    start_game.sendClickData(event->globalX(), event->globalY());
}

