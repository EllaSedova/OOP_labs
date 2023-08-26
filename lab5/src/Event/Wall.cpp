#include "Wall.h"
void Wall::make_event(Player& player, Cell& cell,Level* level){
    cell.setAvailable(true);
    cell.clear();
    notify(1,"Player break wall",level);

}