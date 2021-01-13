//
// Created by georgiana on 24.11.2020.
//

#ifndef CLASSES_LEVEL_H
#define CLASSES_LEVEL_H


#include <QtWidgets/QWidget>
#include "Board.h"

class Level : public QWidget {
Q_OBJECT
private:
    int level; //number of level
    int nWaves; //number of enemy waves. same as level??
    int *waves; // enemies left per wave. len(waves)=nWaves
    int reward; // scor and resources after the end of the level
    int currentWave = 0; //current wave in the level
    bool finished;
    Board board;

public:
    Level();
    ~Level();
    int GetAction(int x, int y);
    Level(int l, int w, int rew);
    int getWaveNumber();
    int *getEnemies();
    int getWave();
    int getNextEnemies(int w);
public slots:
    void update();
    void reset();
};


#endif //CLASSES_LEVEL_H
