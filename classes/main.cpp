#include <iostream>
#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QHBoxLayout>
#include "headers/MainWindow.h"
#include "headers/Menu.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    MainWindow viewWindow;              //main window of the game
    Menu * menu=new Menu();             //small menu window - will be prettier hopefully
    QObject::connect(menu, SIGNAL(start(QString)), &viewWindow, SLOT(start(QString)));  // start button of the menu will trigger the appearance of the game scene
    QObject::connect(menu, SIGNAL(start(QString)), menu->menuWindow, SLOT(hide()));     //satrt button will make the menu screen disappear
    menu->menuWindow->show();

    return app.exec();
}
