#pragma once
#include "Observable.h"
#include "../Observer/Observer.h"
#include <vector>
class Subject: public Observable{

public:
    void addObs(Observer * obs);
    void notify(int lvl, std::string str, Level* level);

protected:
    std::vector<Observer*> observers;

};