#include <iostream>
#include <stdlib.h>
#include "Board.h"

Board::Board() {
    this->state = (int *) malloc(sizeof(int)*9);
}

void Board::set(int i, int j, int v) {
    this->state[i*3+j] = v;
}

int Board::get(int i, int j) {
    return this->state[i*3+j];
}

int *Board::getState() {
    return this->state;
}

/*
 * Return true if found a winning line for turn
 * else return false
 */
bool Board::foundLine(int turn) {
    bool found;

    // Check row line
    for (int i=0; i<3; i++) {
        found = true;
        for (int j=0; j<3; j++) {
            if (this->get(i, j) != turn) {
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }

    // Check col line
    for (int j=0; j<3; j++) {
        found = true;
        for (int i=0; i<3; i++) {
            if (this->get(i, j) != turn) {
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }

    // Check down-right line
    found = true;
    for (int i=0; i<3; i++) {
        if (this->get(i, i) != turn) {
            found = false;
            break;
        }
    }
    if (found) {
        return true;
    }

    // Check down-left line
    found = true;
    for (int i=0; i<3; i++) {
        if (this->get(i, 2-i) != turn) {
            found = false;
            break;
        }
    }
    if (found) {
        return true;
    }

    return false;
}
