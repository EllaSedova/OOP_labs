#pragma once
#include "../Event/Event.h"
#include "../Level/Level.h"
class Event;


class Cell {
private:
    bool playerHere;
    bool available;
    int damage = 20;
    int heal = 30;

public:
    int number;
    Event* event;
    bool isPlayerHere() const;
    void setPlayerHere(bool playerHere);
    bool isAvailable() const;
    void clear();
    int getNumber();
    void setNumber(int number);
    int getDamage();
    void setDamage(int damage);
    int getHeal();
    void setHeal(int heal);
    void setAvailable(bool available);
    void changeEvent(Event* event);
    Cell();
};
