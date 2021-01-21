#include <iostream>
#include "headers/Includes.h"
#include "headers/MainWindow.h"
#include "headers/Menu.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    MainWindow viewWindow;
    Menu* menu = new Menu();             //small menu window - will be prettier hopefully
    QObject::connect(menu, SIGNAL(start(QString)), &viewWindow, SLOT(start(QString)));  // start button of the menu will trigger the appearance of the game scene
    QObject::connect(menu, SIGNAL(start(QString)), menu->menuWindow, SLOT(hide()));     //satrt button will make the menu screen disappear
    menu->menuWindow->show();

    return app.exec();
}
