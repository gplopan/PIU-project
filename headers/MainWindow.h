#include "../headers/Tower.h"
#include "../headers/Includes.h"
#include "../headers/StartGame.h"
#ifndef CLASSES_MW_H
#define CLASSES_MW_H


class MainWindow : public QGraphicsView, public QGraphicsScene, public QObject {
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();
    QGraphicsItem* _items = nullptr;
    QGraphicsView* gameView;
    QGraphicsScene* gameScene;
    StartGame start_game;
    void SetData();
    QVector<Tower> towers;
    QString TowerPosition(int tx, int ty, int ex, int ey);
    bool eventFilter(QObject* watched, QEvent* event);
    void DoAnimation(int towerX, int towerY, int enemyX, int enemyY);
	
public slots:
    void AddTowerToMap(int x, int y);
    void RotateTowardsEnemy(int x, int y);
};

#endif