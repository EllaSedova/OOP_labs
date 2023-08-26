#pragma once
#include "Observer.h"
#include "Concrete_obs.h"
#include "../Level/Level.h"
#include "Message.h"
class Console_obs: public Concrete_obs {
public:

    void update(int lvl,std::string str,Level* level);


};