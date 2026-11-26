#ifndef GAME_H
#define GAME_H
#include "Grid.h"

class Game {

    private : 
    bool state_;
    Grid grid_;

    public : 
    Game();
    bool state();
    void startGame();
    void displayGrid() const;
    void mergeTiles();
};

#endif