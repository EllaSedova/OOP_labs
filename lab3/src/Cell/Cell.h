#pragma once
#include "../Event/Event.h"
#include "../Level/Level.h"
class Event;


class Cell {
private:
    bool playerHere;
    bool available;

public:
    int number;
    Event* event;
    bool isPlayerHere() const;
    void setPlayerHere(bool playerHere);
    bool isAvailable() const;
    void clear();
    void setNumber(int number);
    int getNumber();
    void setAvailable(bool available);
    void changeEvent(Event* event);
    Cell();
};

