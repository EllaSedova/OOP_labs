#pragma once

#include "../Controller/Controller.h"
#include "../Controller/CommandReader.h"

class Mediator: public Subject{
private:
    Controller* controller;
    CommandReader* commandReader;
    void scanCommand(std::string str);
public:
    Mediator();
    void start();

    ~Mediator();
};