#pragma once
class Cell;
#include <iostream>
#include"Player.h"
#include"Cell.h"
#include <string>
#include"Field.h"



class Event {
public:
    virtual void make_event(Player& player, Cell& cell) = 0;
};













//#pragma once
//
//#include "Player.h"
//
//class Event{
//public:
//    virtual void doEvent() = 0;
//};

















//    virtual void make_event(Player* player) = 0;
//    virtual void make_event(Cell* cell) = 0;
//};
