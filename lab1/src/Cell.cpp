#include "Cell.h"

bool Cell::isPlayerHere() const {
    return playerHere;
}

void Cell::setPlayerHere(bool playerHere) {
    Cell::playerHere = playerHere;
}

bool Cell::isAvailable() const {
    return available;
}

void Cell::setAvailable(bool available) {
    Cell::available = available;
}

void Cell::changeEvent(Event *event) {
    delete this->event;
    this->event = event;
}

Cell::Cell() {
    event = nullptr;
    playerHere = false;
    available = true;
}

Cell::~Cell() {
    delete event;
}



