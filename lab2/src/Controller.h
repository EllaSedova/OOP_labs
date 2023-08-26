#pragma once

#include "Field.h"
#include "FieldView.h"
#include "Player.h"
#include "Event.h"
//#include "Cell.h"
class Controller {
private:
    Field* field;
    FieldView* fieldView;
    Player* player;
public:
    Controller(Field *field, FieldView *fieldView, Player *player);

    void move(std::string direction);

    void printField();

    bool canMove(int x, int y);

    ~Controller();
};