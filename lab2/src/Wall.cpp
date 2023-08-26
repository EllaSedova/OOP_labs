#include "Wall.h"
void Wall::make_event(Player& player, Cell& cell){
        cell.setAvailable(true);
        cell.clear();

}