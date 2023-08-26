#include "Controller.h"

Controller::Controller(Field *field, FieldView *fieldView, Player *player):
field(field), fieldView(fieldView), player(player) {}

void Controller::move(std::string direction) {

    int width = field->getWidth();
    int height = field->getHeight();
    int x = field->getPosX();
    int y = field->getPosY();
    int oldX = x;
    int oldY = y;
    if (direction == "w") {
        if (y == 0)
            y += height;
        y--;

    } else if (direction == "s") {
        if (y + 1 == height) {
            y -= height;
        }
        y++;
    } else if (direction == "a") {
        if (x == 0) {
            x += width;
        }
        x--;
    } else if (direction == "d") {
        if (x + 1 == width) {
            x -= width;
        }
        x++;
    }

    if (canMove(x, y)) {
        field->updatePlayerPos(false, oldX, oldY);
        field->updatePlayerPos(true, x, y);
        field->setPlayerPosition(x, y);
    }

        Cell *c = field->getCell(x, y);
        field->getCell(x, y)->event->make_event(*player, *c);
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