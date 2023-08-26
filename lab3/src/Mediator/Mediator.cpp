#include "Mediator.h"


Mediator::Mediator() {



    Level* level = new Level();
    if (level->toConsole())
        addObs(new Console_obs);
    if (level->toFile())
        addObs(new File_obs("out.txt"));
    notify(2,"Start game",level);

    Field* field = new Field(-10,10,level);
    FieldView* fv = new FieldView(field);
    Player* player = new Player(level);
    field->getCell(1,1)->setNumber(4);
    field->getCell(2,2)->setNumber(5);
    controller = new Controller(field, fv, player,*level);
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