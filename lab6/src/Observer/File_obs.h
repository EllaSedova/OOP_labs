#pragma once
#include "Observer.h"
#include "../Level/Level.h"
#include <iostream>
#include <fstream>
#include "Message.h"
#include "Concrete_obs.h"



class File_obs: public Concrete_obs{
private:
    std::ofstream file;
    std::string str;
    int lvl;
public:
    File_obs(std::string fileName);
    void update(int lvl, std::string str, Level *level);
    ~File_obs();
};