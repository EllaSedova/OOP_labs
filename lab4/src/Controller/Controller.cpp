#include "Controller.h"

Controller::Controller(Field *field, FieldView *fieldView, Player *player, Level& level):
        field(field), fieldView(fieldView), player(player), level(level)
        {
    ReadFileConfig config("Config.txt");
    config.readConfig();
    command = config.getConfig();
        }

void Controller::move(char ch) {

    int width = field->getWidth();
    int height = field->getHeight();
    int x = field->getPosX();
    int y = field->getPosY();
    int oldX = x;
    int oldY = y;

    if (command[ch] == "up") {       //up
        if (y == 0)
            y += height;
        y--;

    } else if (command[ch] == "down") {        //down
        if (y + 1 == height) {
            y -= height;
        }
        y++;
    } else if (command[ch] == "right") {    //right
        if (x + 1 == width) {
            x -= width;
        }
        x++;

    } else if (command[ch] == "left") {    //left
        if (x == 0) {
            x += width;
        }
        x--;

    }
    else if (command[ch] == "exit") {    //exit
        player->setExit(true, &level);
    }
    if (canMove(x, y)) {
        field->updatePlayerPos(false, oldX, oldY);
        field->updatePlayerPos(true, x, y);
        field->setPlayerPosition(x, y);
    }

    Cell *c = field->getCell(x, y);
    if (field->getCell(x, y)->number == 0) {
        std::cout<<"Player break wall"<<'\n';
        std::cout << "player armor: " << player->getArmor() << '\n';
        std::cout << "player hp: " << player->getHealthPoint() << '\n';
    }
    if (field->getCell(x, y)->number == 1) {
        std::cout<<"Player stepped into the fire"<<'\n';
        if (player->getArmor() > 0){
            std::cout << "player armor: " << player->getArmor()-50 << '\n';
            std::cout << "player hp: " << player->getHealthPoint() << '\n';
        }
        else if(player->getArmor() <= 0 && player->getHealthPoint() > 50){
            std::cout << "player armor: " << player->getArmor() << '\n';
            std::cout << "player hp: " << player->getHealthPoint()-50 << '\n';
        }
        else if(player->getHealthPoint() == 50){
            std::cout << "player armor: " << player->getArmor() << '\n';
            std::cout << "player hp: " << player->getHealthPoint()-50 << '\n';
            std::cout<<"Game over:("<<'\n';
        }
    }


    if (field->getCell(x, y)->number == 2) {
        std::cout<<"Player found heal"<<'\n';
        std::cout << "player armor: " << player->getArmor() << '\n';
        if (player->getHealthPoint() <100)
            std::cout << "player hp: " << player->getHealthPoint()+50 << '\n';
        else
            std::cout << "player hp: " << player->getHealthPoint() << '\n';
    }
    if (field->getCell(x, y)->number == 3) {
        std::cout << "player armor: " << player->getArmor() << '\n';
        std::cout << "player hp: " << player->getHealthPoint() << '\n';
    }
    if (field->getCell(x, y)->number == 4) {
        std::cout<<"Player found key"<<'\n';
        std::cout << "player armor: " << player->getArmor() << '\n';
        std::cout << "player hp: " << player->getHealthPoint() << '\n';

    }
    if (field->getCell(x, y)->number == 5) {
        std::cout<<"Player found exit"<<'\n';
        std::cout << "player armor: " << player->getArmor() << '\n';
        std::cout << "player hp: " << player->getHealthPoint() << '\n';
        if (player->getKey() ==1)
            std::cout<<"Win!!!"<<'\n';
    }
    field->getCell(x, y)->event->make_event(*player, *c, &level);


}

void Controller::printField() {
    fieldView->printField();
}

Controller::~Controller() {
    delete field;
    delete fieldView;
    delete player;
}

bool Controller::canMove(int x, int y) {
    return field->getCell(x,y)->isAvailable();

}