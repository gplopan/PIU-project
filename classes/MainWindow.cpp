#include "headers/MainWindow.h"
#include <QLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QToolBar>


MainWindow::~MainWindow() {
    delete mainwindow;
}

MainWindow::MainWindow() : QMainWindow(), mainwindow(new QMainWindow)
{
	
}

void MainWindow::SetData()
{
//	// setting the image
//	QWidget* image = new QWidget;
//	image->setGeometry(0, 0, 1350, 800);
//	image->setStyleSheet("background-image: url('./images/level2.png');");
//	mainwindow->layout()->addWidget(image);
//
//	// setting the bottom menu (va trebui sa-l mutam in alt fisier mai incolo)
//	QWidget* bottomMenu = new QWidget;
//	bottomMenu->setGeometry(0, 800, 1350, 80);
//	bottomMenu->setStyleSheet("background-image: url('./images/bottommenu.png');");
//	mainwindow->layout()->addWidget(bottomMenu);
//
//	// va trebui ca menu-ul de jos sa-l setam ca setstatus in mainwindow (vezi documentatia oficiala)
//	mainwindow->setFixedSize(1300, 880);


    QWidget *image = new QWidget;
    image->setGeometry(0, 0, 1350, 800);
    image->setStyleSheet(
            "background-image: url('/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/level2.png');");
    mainwindow->layout()->addWidget(image);

    ///create toolbar and toolbutton w/ icon
    QToolBar *qToolBar = new QToolBar();
    QToolButton *qToolButton = new QToolButton();
    QIcon icon("/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/tower1p1.png");
    qToolButton->setIcon(icon);
    qToolButton->setFixedSize(50,50);

    ///add button to bar
    qToolBar->addWidget(qToolButton);
    ///make bar movable - fix for not knowing how to move it
    qToolBar->setMovable(true);
    ///set the icon size to the size of the button
    qToolBar->setIconSize(QSize(qToolButton->size().width(), qToolButton->size().height() ));


///// TODO legat de ce a facut ionut cu butonul din toolbar. cumva butonul trebuie sa activeze un singur click pentru
///// plasarea unui tower si dupa sa trebuiasca apasat iar SAU sa fie valabil pana la dezactivare

    mainwindow->addToolBar(qToolBar);
    ///860 -> 790 am ecran mic si mi se pare ca imaginea loops oricum in partea de jos la 860 cu noile rezolutii
    mainwindow->setFixedSize(1260, 790);
    mainwindow->show();

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
