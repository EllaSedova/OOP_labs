#pragma once
#include <string>
#include <iostream>
class Level {
private:
    bool info = false;
    bool statement = false;
    bool error = false;
    bool console = false;
    bool file = false;

public:


    Level();
    bool getInfo() const;
    bool getStatement() const;
    bool getError() const;

    bool toConsole() const;
    bool toFile() const;
};
