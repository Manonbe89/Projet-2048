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
    grid_.displayGrid();
    grid_.changeTab();
    std::cout << "after" << std::endl;
    grid_.displayGrid();
}
