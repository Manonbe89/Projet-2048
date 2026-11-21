#include "Grid.h"
#include <random>

Grid::Grid()
:tab_(16, Tile(0)), number_case_(16) {
    srand(time(0));
    for (int i = 0; i < 2; i++){
        int rand_pos = rand() %16;
        int rand_num = rand() %4 + 2;
        while(rand_num != 2 && rand_num != 4){
            rand_num = rand() %4 + 2;
        }
        Tile tile1(rand_num);
        tab_[rand_pos] = tile1;
    }
}

void Grid::displayGrid() const{
    for (int i = 0; i < number_case_; i++ ) {
        std::cout << tab_[i].Value() << " | ";
        if(i%4 == 3){
            std::cout << std::endl;
        }
    }
}