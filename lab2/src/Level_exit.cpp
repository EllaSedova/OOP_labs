
#include "Level_exit.h"

void Level_exit::make_event(Player& player, Cell& cell){
    if (!(player.getKey())){
        cell.setAvailable(true);
    }
    else{
        cell.setAvailable(true);
        std::cout<<"Win!!!:)"<<"\n";
        cell.clear();
        exit(0);

    }
}