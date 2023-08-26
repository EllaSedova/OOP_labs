#pragma once

#include <string>

class Player {
private:
    int healthPoint;
    int damage;
    int armor;
    std::string name;
    bool key;
public:

    Player(int healthPoint, int damage, int armor, std::string name, bool key);

    Player();

    int getHealthPoint() const;

    void setHealthPoint(int healthPoint);

    int getDamage() const;

    void setDamage(int damage);
    bool getKey() const;

    void setKey(bool key);

    int getArmor() const;

    void setArmor(int armor);

    std::string getName() const;

    void setName(const std::string &name);
};
