#pragma once

#include "../Controller/Controller.h"
#include "../Controller/ConsoleCommandReader.h"

class Mediator: public Subject{
private:
    Controller* controller;
    ConsoleCommandReader* commandReader;
    void scanCommand(char str);

public:
    Player* player;
    Mediator();
    void start();

    ~Mediator();
};