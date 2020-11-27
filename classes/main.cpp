#include <iostream>
#include <QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsPixmapItem>
#include <headers/Game.h>
#include <headers/Enemy.h>
#include <QtCore/QPropertyAnimation>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QMainWindow>
#include <QTimer>

QLabel *sprite;

int main(int argc, char **argv) {
    QApplication app(argc, argv);
//    QMainWindow *mainwindow = new QMainWindow();
//
//    QWidget *image = new QWidget;
//    image->setGeometry(0, 0, 1350, 800);
//    image->setStyleSheet(
//            "background-image: url('/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/level2.jpg');");
//    mainwindow->layout()->addWidget(image);
//
//    ///create toolbar and toolbutton w/ icon
//    QToolBar *qToolBar = new QToolBar();
//    QToolButton *qToolButton = new QToolButton();
//    QIcon icon("/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/tower1p1.png");
//    qToolButton->setIcon(icon);
//    qToolButton->setFixedSize(50,50);
//
//    ///add button to bar
//    qToolBar->addWidget(qToolButton);
//    ///make bar movable - fix for not knowing how to move it
//    qToolBar->setMovable(true);
//    ///set the icon size to the size of the button
//    qToolBar->setIconSize(QSize(qToolButton->size().width(), qToolButton->size().height() ));
//

/// TODO legat de ce a facut ionut cu butonul din toolbar. cumva butonul trebuie sa activeze un singur click pentru
/// plasarea unui tower si dupa sa trebuiasca apasat iar SAU sa fie valabil pana la dezactivare

//
//    mainwindow->addToolBar(qToolBar);
//    ///880 -> 800 am ecran mic
//    mainwindow->setFixedSize(1300, 800);
//    mainwindow->show();

//----------------------
//    Game* game=new Game();
//    game->show();
//--------------------
    QWidget *window = new QWidget;
    QPushButton *button1=new QPushButton("start", window);
    Enemy *enemy = new Enemy(1, 1, "enemy.png", window);
    enemy->setGeometry(QRect(300,0,100,100));
//    QObject::connect(button1, SIGNAL(clicked()), enemy, SLOT(reposition()));
    QTimer *timer = new QTimer(window);
    QObject::connect(timer, &QTimer::timeout,  enemy, SLOT(reposition()));
    timer->start(1000);
    window->show();
//----------------------
    return app.exec();
    //insert event related instructions after this
}

void QWidget::mousePressEvent(QMouseEvent *event) {
//    emit start_game.sendClickData(event->x(), event->y());
//    start_game.sendClickData(event->x(), event->y());
}

