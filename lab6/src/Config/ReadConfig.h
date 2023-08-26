#pragma once
#include <map>
#include <utility>
#include <string>
#include <list>
#include "../Player/Player.h"

class ReadConfig {
private:
    std::map<char, std::string> default_command{
            {'w', "up"},
            {'s', "down"},
            {'a', "left"},
            {'d', "right"},
            {'e', "exit"},
    };

public:
    //friend class Config;
    std::list <std::string> Prefix{ "up", "down", "left", "right","exit" };
    std::map <char, std::string> get_default();
};