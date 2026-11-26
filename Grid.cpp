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
    int key = getch();     //pas besoin de mettre entrée 
    if (key == 224){
        key = getch();
        
        if (key == 72){                                         //vers le haut
            for (int i = 0; i < number_case_; i++){
                    if (i > 11){
                        mergeTiles(i, 12, 'v');
                    }
                    else if(i > 7) {
                        mergeTiles(i, 8, 'v');
                    }
                    else if(i > 3) {
                        mergeTiles(i, 4, 'v');
                    }
            }
        }
        else if (key == 80){                                     //vers le bas
            for (int i = 15; i > 0; i--){
                    if (i < 4){
                        mergeTiles(i, -12, 'v');
                    }
                    else if(i < 8) {
                        mergeTiles(i, -8, 'v');
                    }
                    else if(i < 12) {
                        mergeTiles(i, -4, 'v');
                    }
            }
        }
        else if (key == 75){                                      //vers la gauche
            for (int i = 0; i < number_case_; i++){
                    if (i == 1 || i == 5 || i == 9 || i == 13){
                        mergeTiles(i, 1, 'h');
                    }
                    else if(i == 2 || i == 6 || i == 10 || i == 14) {
                        mergeTiles(i, 2, 'h');
                    }
                    else if(i == 3 || i == 7 || i == 11 || i == 15) {
                        mergeTiles(i, 3, 'h');
                    }
            }
        }
        else if (key == 77){                                      //vers la droite
            for (int i = 0; i < number_case_; i++){
                    if (i == 2 || i == 6 || i == 10 || i == 14){
                        mergeTiles(i, -1, 'h');
                    }
                    else if(i == 1 || i == 5 || i == 9 || i == 13) {
                        mergeTiles(i, -2, 'h');
                    }
                    else if(i == 0 || i == 4 || i == 8 || i == 12) {
                        mergeTiles(i, -3, 'h');
                    }
            }
        }
    }  
}

void Grid::mergeTiles(int i, int other, char parametre)
{
    Tile tile0(0);
        if (tab_[i - other].Value() == 0){
                            tab_[i - other] = tab_[i]; 
                            tab_[i] = tile0;
        }
        else if (tab_[i - other].Value() == tab_[i].Value()){
                            tab_[i - other] = tab_[i].Value()*2;
                            tab_[i] = tile0;
        }
        else {
            if(parametre == 'v'){
                tab_[i - other - 4] = tab_[i].Value();
                tab_[i] = tile0;
            }
            else if(parametre == 'h'){
                tab_[i - other - 1] = tab_[i].Value();
                tab_[i] = tile0;
            }
        }
}
