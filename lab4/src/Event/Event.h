#pragma once

class Cell;
#include <iostream>
#include "../Player/Player.h"
#include "../Cell/Cell.h"
#include <string>
#include "../Field/Field.h"
#include "../Observable/Subject.h"
#include"../Level/Level.h"
#include "../Observer/Console_obs.h"
#include "../Observer/File_obs.h"
#include "../Observer/Observer.h"


class Event: public Subject {
public:
    virtual void make_event(Player& player, Cell& cell, Level* level) = 0;
};