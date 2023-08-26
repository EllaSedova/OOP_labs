#pragma once
#include <string>
#include <iostream>
#include "../Level/Level.h"
class Observer {
public:
    virtual void update(int lvl,std::string str,Level* level) = 0;
    virtual ~Observer(){};
};