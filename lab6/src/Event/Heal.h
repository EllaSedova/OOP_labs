#pragma once
#include <string>
#include <iostream>
#include"EventPlayer.h"
class Heal : public EventPlayer {
public:
    void make_event(Player& player, Cell& cell, Level* level);
};
