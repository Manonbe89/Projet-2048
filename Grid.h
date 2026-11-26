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
    int numberCase() const;
    int tab(int i) const;
    void changeTab();
    void mergeTiles(int i, int other, char parametre);
};

#endif