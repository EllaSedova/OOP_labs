#pragma once
#include <string>
#include <iostream>
#include"EventField.h"
class  Clear_cell : public EventField {
public:
    void make_event(Player& player, Cell& cell);
};