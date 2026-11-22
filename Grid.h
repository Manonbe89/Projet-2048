#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include <conio.h>
#include "Tile.h"

class Grid {
    
    private : 
    std::vector<Tile> tab_;
    int number_case_;

    public :
    Grid();
    void displayGrid() const;
    void changeTab();
};

#endif