#include "Cell.h"
#include "../Event/Wall.h"
#include "../Event/fire.h"
#include "../Event/Heal.h"

int Cell::getNumber(){
    return number;
}

void Cell::setNumber(int number) {
    Cell::number = number;
}
int Cell::getDamage(){
    return damage;
}

void Cell::setDamage(int damage) {
    Cell::damage = damage;
}
int Cell::getHeal(){
    return heal;
}

void Cell::setHeal(int heal) {
    Cell::heal = heal;
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
    available = true;
    this->event = event;
}


Cell::Cell() {

    available = true;
    event = new (Clear_cell);
    number = 3;
    playerHere = false;
    damage = 20;
    heal = 30;
}

void Cell::clear() {
    this->event = new (Clear_cell);
    available = true;
    number = 3;
}
