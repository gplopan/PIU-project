#include "Tower.h"
#include "../headers/Includes.h"

#ifndef CLASSES_MW_H
#define CLASSES_MW_H


class MainWindow : public QGraphicsScene {
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();
    QGraphicsItem* _items = nullptr;
    QGraphicsScene* gameScene;
    void SetData();
    QVector<Tower> towers;
    QString TowerPosition(int tx, int ty, int ex, int ey);
public slots:
    void AddTowerToMap(int x, int y);
    void RotateTowardsEnemy(int x, int y);
};

#endif