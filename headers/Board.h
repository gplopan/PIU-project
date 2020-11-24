//
// Created by ionut on 24.11.2020.
//

#ifndef CLASSES_BOARD_H
#define CLASSES_BOARD_H


class Board {
private:
    int **board;
    int level;
public:
    Board(int level);
    ~Board() = default;

    int** getBoard();
    int getLevel();
    };


#endif 
