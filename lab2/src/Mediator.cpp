#include "Mediator.h"

Mediator::Mediator() {
    Field* field = new Field(10,10);
    FieldView* fv = new FieldView(field);
    Player* player = new Player();
    field->getCell(1,1)->setNumber(4);
    field->getCell(2,2)->setNumber(5);

    controller = new Controller(field, fv, player);
    commandReader = new CommandReader();
}

Mediator::~Mediator() {
    delete commandReader;
    delete controller;
}

void Mediator::start() {
    std::cout<<"available commands: a d w s exit"<<"\n";
    controller->printField();
    std::string s = commandReader->readCommand();
    while(s != "exit" && s != "e"){
        scanCommand(s);
        s = commandReader->readCommand();
    }
}

void Mediator::scanCommand(std::string s) {
    if (s == "a" || s == "w" || s == "d" || s == "s"){
        controller->move(s);
        controller->printField();
    }
}