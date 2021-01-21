//
// Created by georgiana on 12.01.2021.
//

#include <QHBoxLayout>
#include "../headers/Menu.h"

Menu::Menu() {
    menuWindow = new QWidget; //menu window with the start button and the player name
    menuWindow->setFixedSize(300, 100);
    menuWindow->setWindowTitle("TOWER DEFENSE");
    nameEdit = new QLineEdit("Player");
    nameEdit->setAlignment(Qt::AlignLeft);
    nameEdit->setMaxLength(20);
    qPushButton = new QPushButton("START");
    qPushButton->setFixedSize(100, 50);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(nameEdit);
    layout->addWidget(qPushButton);
    menuWindow->setLayout(layout);
    QObject::connect(qPushButton, SIGNAL(clicked()), this, SLOT(buttonPressed()));
}

void Menu::buttonPressed() {
    QString qString = nameEdit->text();
    start(qString);
}
