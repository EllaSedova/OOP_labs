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
    player = new Player(level);
    field->getCell(1,1)->setNumber(4);
    field->getCell(2,2)->setNumber(5);
    controller = new Controller(field, fv, player,*level);
    commandReader = new ConsoleCommandReader();


}


Mediator::~Mediator() {
    delete commandReader;
    delete controller;
}

void Mediator::start() {
    controller->printField();
    char ch = commandReader->readCommand();
    while(!(player->getExit()) && controller->command[ch] != "exit"){
        scanCommand(ch);
        ch = commandReader->readCommand();
    }
}


void Mediator::scanCommand(char ch) {
    if (controller->command[ch] == "up" || controller->command[ch] == "down"
    || controller->command[ch] == "right" || controller->command[ch] == "left"){
        controller->move(ch);
        controller->printField();
    }
}
