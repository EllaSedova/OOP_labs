#include "fire.h"

void fire::make_event(Player& player, Cell& cell, Level* level) {

    if (player.getArmor() > 0){
        player.setArmor(player.getArmor() - cell.getDamage(),level);
        if(player.getArmor()<0)
        {
            player.setHealthPoint(player.getHealthPoint() + player.getArmor(), level);
            player.setArmor(0, level);
        }
        notify(1,"Player stepped into the fire",level);
    }
    else if(player.getArmor() == 0 && player.getHealthPoint() > 0){
        player.setHealthPoint(player.getHealthPoint() - cell.getDamage(),level);
        notify(1,"Player stepped into the fire",level);
        if(player.getHealthPoint() <= 0){
            player.setHealthPoint(0,level);
            notify(1,"Player stepped into the fire",level);
            notify(2,"End game",level);
            player.setExit(true,level);
        }
    }
    cell.clear();
}