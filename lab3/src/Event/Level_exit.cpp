#include "Level_exit.h"

void Level_exit::make_event(Player& player, Cell& cell,Level* level){
    if (!(player.getKey())){
        cell.setAvailable(true);
    }
    else {
        cell.setAvailable(true);
        if (cell.isPlayerHere()) {
            notify(1, "Player found exit", level);
            notify(2, "End game", level);
            exit(0);
        }
    }
}
