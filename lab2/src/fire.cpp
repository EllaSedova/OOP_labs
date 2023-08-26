#include "fire.h"

void fire::make_event(Player& player, Cell& cell) {
    if (player.getArmor() > 0){
        player.setArmor(player.getArmor() - 50);
        std::cout<<"player armor: "<<player.getArmor()<<'\n';
    }
    else if(player.getArmor() <= 0){
        player.setHealthPoint(player.getHealthPoint() - 50);
        std::cout<<"player hp: "<<player.getHealthPoint()<<'\n';
    }
    else if(player.getHealthPoint() <= 0){
        std::cout<<"Game over:("<<'\n';
        exit(0);
    }
    cell.clear();
}













//    int a = player.getHealthPoint();
//    a = a-50;
//    player.setc(a);}


