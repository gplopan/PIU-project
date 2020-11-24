#include "headers/Functions.h"
#include "headers/Includes.h"
using namespace std;

void SetBackgroundImage(QString qs, QMainWindow &window)
{
    QPixmap bkgnd(qs);
    bkgnd = bkgnd.scaled(window.size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    window.setPalette(palette);
}