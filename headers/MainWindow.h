#include "../headers/Includes.h"

#ifndef CLASSES_MW_H
#define CLASSES_MW_H


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();
    void setFoo(char* text);
    QMainWindow* mainwindow;
    void SetData();

public slots:
    void AddTowerToMap(int x, int y);
    
};

#endif