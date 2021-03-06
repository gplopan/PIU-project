
#ifndef CLASSES_MW_H
#define CLASSES_MW_H

#include <qmainwindow.h>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGraphicsScene>
#include <QGraphicsObject>
#include "Tower.h"
#include "StartGame.h"
#include "Enemy.h"

class MainWindow : public QGraphicsView{
Q_OBJECT
private:
    bool place=false;
    QVector<QGraphicsRectItem*> squares;
    QVector<Tower> towers;
    QVector<Enemy*> enemies;
    QTimer *advanceTimer;
    QGraphicsTextItem *playerInfo;
public:
    QGraphicsView* gameView;
    QGraphicsScene* gameScene;
    StartGame * start_game;


    explicit MainWindow();
    ~MainWindow();
    void SetData(int level);
    QString TowerPosition(int tx, int ty, int ex, int ey);
    bool eventFilter(QObject* watched, QEvent* event);
    void updateInfo();
signals:
    inline void beginLevel();

public slots:
    void AddTowerToMap(int x, int y);
    void RotateTowardsEnemy(int x, int y);
    void start(QString playerName);
    void drawEnemy();
    void lost();
    void reset(bool reset);
    void nextLevel(bool ss=true);
    void validate();
};

#endif