
#include "Key.h"

void Key::make_event(Player& player, Cell& cell) {
    if (!player.getKey()) {
        player.setKey(true);
    }
    std::cout<<"Key!!!"<<'\n';
    cell.clear();
}