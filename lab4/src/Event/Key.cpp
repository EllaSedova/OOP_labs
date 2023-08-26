#include "Key.h"

void Key::make_event(Player& player, Cell& cell,Level* level) {
    if (!player.getKey()) {
        player.setKey(true,level);
    }
    notify(1,"Player found key",level);
    Console_obs a;

    cell.clear();
}
