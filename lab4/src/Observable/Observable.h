#pragma once
#include <string>
#include "../Observer/Observer.h"
#include "../Level/Level.h"
class Observable {
public:
    virtual void addObs(Observer * obs) = 0;
    virtual void notify(int lvl, std::string str, Level* level) = 0;
};