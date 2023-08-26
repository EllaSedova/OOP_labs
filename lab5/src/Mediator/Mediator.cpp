#include "Mediator.h"
#include "../Rules/KeyRule.h"
#include "../Rules/DefaultRule.h"
#include "../Rules/PoseRule.h"
#include "../Rules/ExitRule.h"
#include "../Rules/EventRule.h"
#include "../Rules/DamageRule.h"
#include "../Rules/HealRule.h"
#include "../Rules/FieldSizeRule.h"
#include "../FieldGenerator/FieldGenerator.h"

Mediator::Mediator() {

    level = new Level();
    if (level->toConsole())
        addObs(new Console_obs);
    if (level->toFile())
        addObs(new File_obs("out.txt"));
    notify(2,"Start game",level);
    player = new Player(level);
    createField();
    FieldView* fv = new FieldView(field);
    controller = new Controller(field, fv, player,*level);
    commandReader = new ConsoleCommandReader();
}
void Mediator::createField(){
    char lvl;
    std::cout << "Choose level[1/2]: ";
    while (lvl != '1' && lvl != '2') {
        std::cin >> lvl;
        std::cout << '\n';
    }
    if (lvl == '1') {
        createFirstLevel();
    } else {
        createSecondLevel();
    }
}

void Mediator::createFirstLevel() {

    FieldGenerator<FieldSizeRule<15,15> ,DefaultRule<6,10,2>,EventRule<1, 10>,EventRule<2, 9>, //EventRule 0 - wall, 1 - fire, 2 - heal
            EventRule<0, 20>,DamageRule<50>,HealRule<25>,DefaultRule<5,0,0>,
            DefaultRule<4,1,1>> gen;
    field = gen.generate();
    field->CheckField(field);
}

void Mediator::createSecondLevel() {

    FieldGenerator<DefaultRule<5,0,0>,DefaultRule<6,2,2>,
            DefaultRule<4,1,1>,FieldSizeRule<15,4>> gen;//DefaultRule 4 - key, 5 - exit, 6 - player
    field = gen.generate();
    field->CheckField(field);
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
