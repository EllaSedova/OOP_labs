#include "fire.h"

void fire::make_event(Player& player, Cell& cell, Level* level) {

    if (player.getArmor() > 0){
        player.setArmor(player.getArmor() - 50,level);
        notify(1,"Player stepped into the fire",level);
    }
    else if(player.getArmor() <= 0 && player.getHealthPoint() > 50){
        player.setHealthPoint(player.getHealthPoint() - 50,level);
        notify(1,"Player stepped into the fire",level);
    }
    else if(player.getHealthPoint() == 50){
        player.setHealthPoint(player.getHealthPoint() - 50,level);
        notify(1,"Player stepped into the fire",level);
        notify(2,"End game",level);
        player.setExit(true,level);
    }

    cell.clear();
}