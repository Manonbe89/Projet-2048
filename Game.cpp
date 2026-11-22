#include "Game.h"

Game::Game()
:state_(0)
{
}

bool Game::state()
{
    return state_;
}

void Game::startGame()
{
    Grid grid;
    grid.displayGrid();
}

void Game::moveTiles()
{
    int key = getch();     //pas besoin de mettre entrée 
    if (key == 224)
        key = getch();
    switch(key)
    {
        case 72 : key = 'h'; break;
        case 80 : key = 'b'; break;
        case 75 : key = 'g'; break;
        case 77 : key = 'd'; break;
    }
}