#include "headers/MainWindow.h"
#include <QLayout>
MainWindow::~MainWindow() {
    delete mainwindow;
}

MainWindow::MainWindow() : QMainWindow(), mainwindow(new QMainWindow)
{
	
}

void MainWindow::SetData()
{
	// setting the image
	QWidget* image = new QWidget;
	image->setGeometry(0, 0, 1350, 800);
	image->setStyleSheet("background-image: url('./images/level2.jpg');");
	mainwindow->layout()->addWidget(image);

	// setting the bottom menu (va trebui sa-l mutam in alt fisier mai incolo)
	QWidget* bottomMenu = new QWidget;
	bottomMenu->setGeometry(0, 800, 1350, 80);
	bottomMenu->setStyleSheet("background-image: url('./images/bottommenu.png');");
	mainwindow->layout()->addWidget(bottomMenu);
	
	// va trebui ca menu-ul de jos sa-l setam ca setstatus in mainwindow (vezi documentatia oficiala)
	mainwindow->setFixedSize(1300, 880);

}

void MainWindow::AddTowerToMap(int x, int y)
{
//	qDebug() << "mesaj = " << x << " , " << y;

	//calculam pozitia sa punem turnul fix pe tile
	int pozX = x / 70;
	int pozY = y / 70;
	
	QWidget* image = new QWidget;
	image->setGeometry(pozX * 70, pozY*70, 70, 70);
	image->setStyleSheet("background-image: url('./images/tower1p4.png');");
	mainwindow->layout()->addWidget(image);
}
