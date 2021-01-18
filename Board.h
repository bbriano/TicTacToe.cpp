#ifndef BOARD_H
#define BOARD_H

class Board {
    int *state;
public:
    Board();

    void set(int i, int j, int v);
    int get(int i, int j);

    int *getState();

    bool foundLine(int turn);
};

#endif
