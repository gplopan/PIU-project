#include <iostream>
#include <QApplication>
#include <headers/Game.h>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    Game* game=new Game();
    game->show();
    return app.exec();
}

void QWidget::mousePressEvent(QMouseEvent *event) {
//    emit start_game.sendClickData(event->x(), event->y());
//    start_game.sendClickData(event->x(), event->y());
}

