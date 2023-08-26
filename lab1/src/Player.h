#pragma once

#include <string>

class Player {
private:
    int healthPoint;
    int damage;
    int armor;
    std::string name;
public:
    Player(int healthPoint = 100, int damage = 100, int armor = 100, std::string name = "no_name");

    int getHealthPoint() const;

    void setHealthPoint(int healthPoint);

    int getDamage() const;

    void setDamage(int damage);

    int getArmor() const;

    void setArmor(int armor);

    std::string getName() const;

    void setName(const std::string &name);
};
