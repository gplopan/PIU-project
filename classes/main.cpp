#include <iostream>
#include <QApplication>
#include <QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsPixmapItem>
#include <headers/Game.h>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

//    QWidget *window = new QWidget;
//    QPushButton *button1 = new QPushButton("Start this shit");
//    QPushButton *button2 = new QPushButton("Two");
//    QPushButton *button3 = new QPushButton("Three");
//    QHBoxLayout *layout = new QHBoxLayout;
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

    Game* game=new Game();
    game->show();
    return app.exec();
    //insert event related instructions after this


}
