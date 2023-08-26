#include "Event.h"
#pragma once

class Cell {
private:
    Event* event;
    bool playerHere;
    bool available;
public:
    bool isPlayerHere() const;

    void setPlayerHere(bool playerHere);

    bool isAvailable() const;

    void setAvailable(bool available);

    void changeEvent(Event* event);

    Cell();


    ~Cell();
};
