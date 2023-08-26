#include "Heal.h"

void Heal::make_event(Player& player, Cell& cell,Level* level) {

    if (player.getHealthPoint() < 100) {
        int hp = player.getHealthPoint();
        hp = hp + cell.getHeal();
        player.setHealthPoint(hp,level);
        if (player.getHealthPoint() > 100)
            player.setHealthPoint(100,level);

        notify(1,"Player found heal",level);

    }
    cell.clear();
}
