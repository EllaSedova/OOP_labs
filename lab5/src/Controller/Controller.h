#pragma once

#include "../Field/Field.h"
#include "../Field/FieldView.h"
#include "../Player/Player.h"
#include "../Event/Event.h"
#include "../Level/Level.h"
#include "../Observer/Console_obs.h"
#include "../Observer/File_obs.h"
#include "../Observer/Observer.h"
#include "../Controller/ConsoleCommandReader.h"
#include "../Config/ReadFileConfig.h"
#include "../Config/Config.h"


class Controller {
private:
    Field* field;
    FieldView* fieldView;
    Player* player;
    Level& level;
public:
    std::map<char, std::string> command;

    Controller(Field *field, FieldView *fieldView, Player *player, Level &level);

    void move(char ch);

    void printField();

    bool canMove(int x, int y);

    ~Controller();
};
