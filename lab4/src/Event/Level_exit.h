#pragma once
#include <string>
#include <iostream>
#include "EventPlayer.h"
class Level_exit : public EventPlayer {
public:
    void make_event(Player& player, Cell& cell, Level* level);
};
