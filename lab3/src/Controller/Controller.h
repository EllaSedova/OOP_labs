#pragma once

#include "../Field/Field.h"
#include "../Field/FieldView.h"
#include "../Player/Player.h"
#include "../Event/Event.h"
#include "../Level/Level.h"
#include "../Observer/Console_obs.h"
#include "../Observer/File_obs.h"
#include "../Observer/Observer.h"
//#include "Cell.h"
class Controller {
private:
    Field* field;
    FieldView* fieldView;
    Player* player;
    Level& level;
public:
    Controller(Field *field, FieldView *fieldView, Player *player, Level &level);

    void move(std::string direction);

    void printField();

    bool canMove(int x, int y);

    ~Controller();
};
