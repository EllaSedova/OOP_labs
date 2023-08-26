#include "Player.h"

#include <utility>

int Player::getHealthPoint() const {
    return healthPoint;
}

void Player::setHealthPoint(int healthPoint) {
    Player::healthPoint = healthPoint;
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

Player::Player(int healthPoint, int damage, int armor, std::string name) : healthPoint(healthPoint),
                                                                           damage(damage), armor(armor),
                                                                           name(std::move(name)) {}
