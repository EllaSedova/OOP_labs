#include "Cell.h"
#include "Wall.h"
#include "fire.h"
#include "Heal.h"

int Cell::getNumber(){
    return number;
}

void Cell::setNumber(int number) {
    Cell::number = number;
}

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
    playerHere = false;
    number = rand()%4;
    switch (number) {
        case 0: {
            event = new (Wall);
            available = false;
            break;
        }
        case 1: {
            event = new(fire);
            available = true;
            break;
        }

        case 2: {
            event = new (Heal);
            available = true;

            break;
        }
        case 3: {
            event = new (Clear_cell);
            available = true;
            break;
        }

        default:
            break;

    }
}

void Cell::clear() {
    this->event = new(Clear_cell);
    available = true;
    number = 3;
}







