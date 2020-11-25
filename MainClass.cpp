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


	// setting the bottom menu (va trebui sa-l mutam in alt fisier mai incolo)
    QWidget* bottomMenu = new QWidget;
    bottomMenu->setGeometry(0, 800, 1350, 80);
    bottomMenu->setStyleSheet("background-image: url('./images/bottommenu.png');");
    mainwindow.layout()->addWidget(bottomMenu);

    // ma joc cu widget
   

	
	//**** va trebui ca menu-ul de jos sa-l setam ca setstatus in mainwindow (vezi documentatia oficiala)
    mainwindow.setFixedSize(1350, 880);

    
	// qDebug() << "Debug"; => folosim qDebug() pentru debug "profesionist"
    
	
	mainwindow.show();
    
    // start the window 
   
    return app.exec();
}

void QWidget::mousePressEvent(QMouseEvent* event)
{
    start_game.sendClickData(event->x(), event->y());
    
}

