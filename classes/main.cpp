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
#include <QtWidgets/QMainWindow>
#include <QMoveEvent>

QLabel *sprite;

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    QPushButton *button1 = new QPushButton("Start this shit",window);
//    QVBoxLayout *layout = new QVBoxLayout;
//    layout->addWidget(button1);
//    layout->addWidget(button2);
//    layout->addWidget(button3);
//    window->setLayout(layout);
//    button1->show();
//    window->show();
//    QGraphicsScene scene;
    //scene.addText("Hello, world!");


//    QImage image("/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/.png"); //necesita for some reason full path -> tbd
//    if(image.isNull())
//        exit(77);
//    QGraphicsPixmapItem pixmapItem( QPixmap::fromImage(image));
//    scene.addItem(&pixmapItem);
//    QGraphicsView view(&scene);
//    view.show();


//    Game* game=new Game();
//    game->show();
//    QMainWindow mainwindow;
    Enemy *enemy = new Enemy(1, 1, "enemy.png",window);

//    QLabel *sprite=new QLabel(window);
//    string name="/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/"+enemy->sprintName
    QPixmap pix("/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/enemy.png");
    int w = 100;
    int h = 100;
    enemy->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    enemy->setGeometry(QRect(300,0,100,100));
    QObject::connect(button1, SIGNAL(clicked()), enemy, SLOT(reposition()));
    window->show();

//    QWidget* image = new QWidget;
//    image->setGeometry(0, 0, 1350, 800);
//    image->setStyleSheet("background-image: url('/home/georgiana/Facultate/an_IV/piu/PIU-project/classes/resources/images/level2.jpg');");
//    mainwindow.layout()->addWidget(image);
//    mainwindow.show();

//window->show();
//    QPropertyAnimation animation(sprite, "geometry");
//    animation.setDuration(10000);
//
//    animation.setKeyValueAt(0, QRect(0, 0, 100, 30));
//    animation.setKeyValueAt(0.8, QRect(250, 250, 100, 30));
//    animation.setKeyValueAt(1, QRect(0, 0, 100, 30));
//
//    animation.start();

    return app.exec();
    //insert event related instructions after this
}

