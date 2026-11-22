#ifndef GAME_H
#define GAME_H
#include <conio.h>
#include "Grid.h"

class Game {

    private : 
    bool state_;

    public : 
    Game();
    bool state();
    void startGame();
    void moveTiles();
    void mergeTiles();
};

#endif