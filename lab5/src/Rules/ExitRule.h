#pragma once
#include "Field.h"
#include "Level_exit.h"
template <unsigned int x>
class ExitRule {
public:
    int flag = 0;
public:
    void fill(Field * field)
    {
        for (int i = 0; i < field->getHeight(); ++i) {
            for (int j = 0; j < field->getWidth(); ++j)
                if(rand() % x == 1 && (field->getCell(j, i)->isPlayerHere())==0 && flag == 0 && field->getCell(j, i)->getNumber()!=4){
                    field->getCell(j, i)->clear();
                    field->getCell(j, i)->changeEvent(new Level_exit());
                    field->getCell(j, i)->setNumber(5);
                    flag+=1;
                    break;
                }
            if (!flag){
                field->getCell(2, 2)->clear();
                field->getCell(2, 2)->changeEvent(new Level_exit());
                field->getCell(2, 2)->setNumber(5);
            }
            break;
        }
    }
};

