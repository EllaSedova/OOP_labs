#pragma once
#include "Field.h"
#include "Level_exit.h"
template <unsigned int event, unsigned int x,unsigned  int y>
class DefaultRule {
public:
    void fill(Field * field)
    {
        if (y<=field->getHeight() && x<=field->getWidth()) {
            if (event == 4) {
                field->getCell(x, y)->clear();
                field->getCell(x, y)->changeEvent(new Key());
                field->getCell(x, y)->setNumber(4);
            }
            if (event == 5) {
                field->getCell(x, y)->clear();
                field->getCell(x, y)->changeEvent(new Level_exit());
                field->getCell(x, y)->setNumber(5);
            }
            if (event == 6) {
                field->getCell(x, y)->clear();
                field->setPlayerPosition(x, y);
                field->getCell(x, y)->setPlayerHere(1);
            }
        }
    }
};

