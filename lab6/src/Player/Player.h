#pragma once
#include "../Observable/Subject.h"
#include <string>
#include "../Level/Level.h"
#include "../Observer/Console_obs.h"
#include "../Observer/File_obs.h"
#include <fstream>
#include <vector>

class Player: public Subject{
private:
    int er = 0;
    int healthPoint;
    int damage;
    int armor;
    std::string name;
    bool key;
    bool exit;
    size_t hashPlayer=0;
    size_t hashPlayerfile=0;
    std::vector<int> mas ={0,0,0};

public:

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
    void savePlayer(std::string fileName);
    void reloadPlayer(std::string fileName);
    void del(std::string line);
    bool isDigit(std::string line);
    void reloadCorrectState();
    bool isEqual(size_t a,size_t b);
    size_t gethashPlayerfile() const;
    size_t gethashPlayer() const;
};
