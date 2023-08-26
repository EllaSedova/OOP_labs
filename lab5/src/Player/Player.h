#pragma once
#include "../Observable/Subject.h"
#include <string>
#include "../Level/Level.h"
#include "../Observer/Console_obs.h"
#include "../Observer/File_obs.h"

class Player: public Subject {
private:
    int healthPoint;
    int damage;
    int armor;
    std::string name;
    bool key;
    bool exit;

public:
    enum Moves{
        UP,
        DOWN,
        LEFT,
        RIGHT,
        EXIT,
        MENU,
        NOTHING
    };
    Player(int healthPoint, int damage, int armor, std::string name, bool key, bool exit);

    Player(Level* level);

    int getHealthPoint() const;

    void setHealthPoint(int healthPoint,Level* level);

    int getDamage() const;

    void setDamage(int damage);
    bool getKey() const;

    void setKey(bool key,Level* level);
    bool getExit() const;

    void setExit(bool exit,Level* level);

    int getArmor() const;

    void setArmor(int armor,Level* level);

    std::string getName() const;

    void setName(const std::string &name);
};
