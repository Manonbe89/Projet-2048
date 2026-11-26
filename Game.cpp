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
    //while(state_ == 0){
        displayGrid();
        grid_.changeTab();
        displayGrid();
    //}
}

void Game::displayGrid() const{
    for (int i = 0; i < grid_.numberCase() ; i++ ) {
        std::cout << grid_.tab(i) << " | ";
        if(i%4 == 3){
            std::cout << std::endl;
        }
    }
}
