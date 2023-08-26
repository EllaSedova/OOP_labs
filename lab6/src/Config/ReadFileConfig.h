#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "ReadConfig.h"
#include <algorithm>
class ReadFileConfig: public ReadConfig{

private:
    std::fstream file;
    std::string line;
    bool command_exist = false;
    int count = 0;

    std::string command;
    std::map <char, std::string> config;

public:
    bool error = false;
    ReadFileConfig(std::string filename);
    std::map <char, std::string> getConfig();
    void readConfig();
    ~ReadFileConfig();


};
