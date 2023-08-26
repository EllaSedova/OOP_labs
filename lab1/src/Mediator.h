#pragma once

#include "Controller.h"
#include "CommandReader.h"

class Mediator {
private:
    Controller* controller;
    CommandReader* commandReader;
    void scanCommand(std::string str);
public:
    Mediator();
    void start();

    ~Mediator();
};