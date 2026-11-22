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
        Tile tile(rand_num);
        tab_[rand_pos] = tile;
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

void Grid::changeTab()
{
    Tile tile0(0);
    int key = getch();     //pas besoin de mettre entrée 
    if (key == 224){
        key = getch();
        
        if (key == 72){
            for (int i = 0; i < 16; i++){
                if (tab_[i].Value() == 0){
                    if(i <12) {
                        tab_[i] = tab_[i+4];
                        tab_[i+4] = tile0;
                    }
                    else
                        tab_[i] = tile0;
                }
            }
        }
    }

    /*{
        case 72 : key = 'h'; break;
        case 80 : key = 'b'; break;
        case 75 : key = 'g'; break;
        case 77 : key = 'd'; break;
    }*/
}
