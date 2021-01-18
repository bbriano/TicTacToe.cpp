#include <iostream>
#include <string>
#include <vector>
#include "Board.h"
#include "Utils.h"
#define P1_CHAR "X"
#define P2_CHAR "O"

void renderBoard(int *);
void readCoordinate(std::string prompt, int *row, int *col);

int main() {
    std::cout
        << "Welcome to TicTacToe!\n"
        << "<player>: <row> <col>\n"
        << P1_CHAR << ": 1 2\n\n";

    Board b;
    int turn = 1;
    std::string input;
    int row, col;

    pause();

    // Game loop
    for (int i=0; i<9; i++) {
        // Display board in console
        renderBoard(b.getState());

        // Get coordinate
        while (1) {
            if (turn == 1) {
                readCoordinate(
                    (std::string) P1_CHAR+": ",
                    &row, &col);
            } else {
                readCoordinate(
                    (std::string) P2_CHAR+": ",
                    &row, &col);
            }

            // Check if cell is valid
            if (b.get(row, col) == 0) {
                break;
            }
        }

        // Update board state
        b.set(row, col, turn);

        // Check if we have a winner!
        if (b.foundLine(turn)) {
            break;
        }

        // Swap turns
        turn = turn == 1 ? 2 : 1;
    }

    std::cout
        << (turn == 1 ? P1_CHAR : P2_CHAR)
        << " wins!\n";
}

// Display board state to console in a grid
void renderBoard(int *boardState) {
    clearScreen();

    std::cout << "+---+---+---+\n";

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            std::cout << "| ";
            switch (boardState[i*3+j]) {
            case 0:
                std::cout << " ";
                break;
            case 1:
                std::cout << P1_CHAR;
                break;
            case 2:
                std::cout << P2_CHAR;
                break;
            }
            std::cout << " ";
        }

        std::cout
            << "|\n"
            << "+---+---+---+\n";
    }
}

// Read and validate user given coordinate
void readCoordinate(std::string prompt, int *row, int *col) {
    std::string r, c;
    while (1) {
        std::string input = toLower(readInput(prompt));
        int spaceIndex = input.find(' ');
        if (!(spaceIndex == std::string::npos)) {
            r = input.substr(0, spaceIndex);
            c = input.substr(spaceIndex + 1);
        }

        if (isInteger(r) && isInteger(c)) {
            // Offset by 1 so player don't play in 0-indexed
            *row = stoi(r) - 1;
            *col = stoi(c) - 1;

            // exit infinite loop if valid coordinate
            if (*row >= 0 && *row < 3 &&
                *col >= 0 && *col < 3) {
                break;
            }
        }
    }
}
