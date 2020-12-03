#include "headers/MainWindow.h"
#include "headers/Includes.h"
#include "headers/StartGame.h"




int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MainWindow viewWindow;
	viewWindow.SetData();
    // connections
 
    // qDebug() << "Debug"; => folosim qDebug() pentru debug "profesionist"

   
    return app.exec();
}
//  virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

