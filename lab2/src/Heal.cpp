
#include "Heal.h"

void Heal::make_event(Player& player, Cell& cell) {
    if (player.getHealthPoint() < 100) {
        int a = player.getHealthPoint();
        a = a + 50;
        if (player.getHealthPoint() > 100)
            player.setHealthPoint(100);
        else
            player.setHealthPoint(a);
        std::cout << "player hp: " << player.getHealthPoint() << '\n';
    }
    cell.clear();
}




























//#include "Heal.h"
//
//std::string HealthDownEvent::doEvent(Player *player) {
//    int hp = player->getHealthPoint();
//    hp-=value;
//    if (hp <= 0) {
//        player->setHealthPoint(0);
//        return "lose";
//    }
//    player->setHealthPoint(hp);
//    return "";
//}
//
//HealthDownEvent::HealthDownEvent(int value) : StatsEvent(value) {}
