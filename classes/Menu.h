//
// Created by georgiana on 12.01.2021.
//

#ifndef CLASSES_MENU_H
#define CLASSES_MENU_H


#include <QLineEdit>
#include <QPushButton>

class Menu  : public QObject {
Q_OBJECT
public:
    QWidget * menuWindow;
    QLineEdit * nameEdit;       // widget from menu screen for inputing the name of the player
    QPushButton *qPushButton;   // start button on the menu screen - is connected to the start() slot
    Menu();
signals:
    void start(QString playerName);
public slots:
    void buttonPressed();
};


#endif //CLASSES_MENU_H
