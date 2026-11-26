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

int Grid::numberCase() const
{
    return number_case_;
}

int Grid::tab(int i) const
{
    return tab_[i].Value();
}

void Grid::changeTab()
{
    Tile tile0(0);
    int key = getch();     //pas besoin de mettre entrée 
    if (key == 224){
        key = getch();
        
        if (key == 72){                                         //vers le haut
            for (int i = 0; i < number_case_; i++){
                if (tab_[i].Value() == 0){
                    if(i < number_case_ - 4) {
                        tab_[i] = tab_[i+4];
                        tab_[i+4] = tile0;
                    }
                    else
                        tab_[i] = tile0;
                }
            }
        }
        else if (key == 80){                                     //vers le bas
            for (int i = 0; i < number_case_; i++) {
                if (tab_[number_case_ - 1 - i].Value() == 0){
                    if(i < number_case_ - 4) {
                        tab_[number_case_ - 1 - i] = tab_[number_case_ - 5 - i];
                        tab_[number_case_ - 5 - i] = tile0;
                    }
                    else
                        tab_[number_case_ - 1 - i] = tile0;
                }
            }
        }
        else if (key == 75){                                      //vers la gauche
            for (int i = 0; i < number_case_; i++) {
                if (tab_[i].Value() == 0){
                    if(i != 3 && i != 7 && i != 11 && i != 15) {
                        tab_[i] = tab_[i + 1];
                        tab_[i + 1] = tile0;
                    }
                    else
                        tab_[i] = tile0;
                }
            }
        }
        else if (key == 77){                                      //vers la droite
            for (int i = 0; i < number_case_; i++) {
                if (tab_[number_case_ - 1 - i].Value() == 0){
                    if(i != 0 && i != 4 && i!= 8 && i != 12) {
                        tab_[number_case_ - 1 - i] = tab_[number_case_ - 2 - i];
                        tab_[number_case_ - 2 - i] = tile0;
                    }
                    else
                        tab_[i] = tile0;
                }
            }
        }
    }

    /*{
        case 77 : key = 'd'; break;
    }*/
}
