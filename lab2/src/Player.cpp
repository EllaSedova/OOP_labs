#include "Player.h"

#include <utility>// для move(name)

Player::Player(int healthPoint, int damage, int armor, std::string name, bool key) :
healthPoint(healthPoint), damage(damage), armor(armor), name(std::move(name)), key(key) {}

Player::Player(): healthPoint(100), damage(0), armor(100), name(std::string("Pupa")), key(false){}

int Player::getHealthPoint() const {
    return healthPoint;
}

void Player::setHealthPoint(int healthPoint) {
    Player::healthPoint = healthPoint;
}
bool Player::getKey() const {
    return key;
}
void Player::setKey(bool key) {
        Player::key = key;
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

void Player::setArmor(int armor) {
    Player::armor = armor;
}

std::string Player::getName() const {
    return name;
}

void Player::setName(const std::string &name) {
    Player::name = name;
}

