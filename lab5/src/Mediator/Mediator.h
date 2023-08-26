#pragma once

#include "../Controller/Controller.h"
#include "../Controller/ConsoleCommandReader.h"

class Mediator: public Subject{
private:
    Controller* controller;
    ConsoleCommandReader* commandReader;
    Player* player;
    Field* field;
    Level* level;
    void scanCommand(char str);
    //Field* field;



public:
    void createFirstLevel();
    void createSecondLevel();
    void createField();
    Mediator();
    void start();

    ~Mediator();
};