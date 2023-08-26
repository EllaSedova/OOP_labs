#include "Player.h"

#include <utility>// для move(name)

Player::Player(int healthPoint, int damage, int armor, std::string name, bool key, bool exit) :
        healthPoint(healthPoint), damage(damage), armor(armor), name(std::move(name)), key(key), exit(exit) {

}

Player::Player(Level* level): healthPoint(100), damage(0), armor(100), name(std::string("Bebra")), key(false), exit(false){

    if (level->toConsole())
        addObs(new Console_obs);
    if (level->toFile())
        addObs(new File_obs("out.txt"));
}

int Player::getHealthPoint() const {
    return healthPoint;
}

void Player::setHealthPoint(int healthPoint,Level* level) {
    Player::healthPoint = healthPoint;

    notify(1,"Change HP",level);

}
bool Player::getKey() const {
    return key;
}
void Player::setKey(bool key,Level* level) {
    Player::key = key;
    notify(1,"Get key",level);
}
bool Player::getExit() const {
    return exit;
}
void Player::setExit(bool exit,Level* level) {
    Player::exit = exit;
    //notify(1,"Exit",level);
}

int Player::getDamage() const {
    return damage;
}

void Player::setDamage(int damage) {
    Player::damage = damage;
}

int Player::getArmor() const {
    return armor;
}

void Player::setArmor(int armor,Level* level) {
    Player::armor = armor;
    notify(1,"Change armor",level);
}


std::string Player::getName() const {
    return name;
}

void Player::setName(const std::string &name) {
    Player::name = name;
}
