#include "Mediator.h"

Mediator::Mediator() {
    Field* field = new Field(5,5);
    FieldView* fv = new FieldView(field);
    Player* player = new Player();
    // Задавание препятствий - начало
    field->updateAvailable(false, 0,2);
    field->updateAvailable(false, 1,2);
    field->updateAvailable(false, 2,2);

    // Задавание препятствий - конец

    controller = new Controller(field, fv, player);
    commandReader = new CommandReader();
}

Mediator::~Mediator() {
    delete commandReader;
    delete controller;
}

void Mediator::start() {
    std::cout<<"available commands: left right up down exit"<<"\n";
    controller->printField();
    std::string s = commandReader->readCommand();
    while(s != "exit" && s != "e"){
        scanCommand(s);
        s = commandReader->readCommand();
    }
}

void Mediator::scanCommand(std::string s) {
    if (s == "up" || s == "down" || s == "left" || s == "right"){
        controller->move(s);
        controller->printField();
    }
}