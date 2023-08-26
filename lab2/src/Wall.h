#pragma once
#include <string>
#include <iostream>
#include "EventField.h"
#include "Clear_cell.h"
class  Wall : public EventField {
public:
    void make_event(Player& player, Cell& cell);
};
