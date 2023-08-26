#pragma once
#include "Field.h"

template <unsigned int x>
class PoseRule {
private:
    int flag =0;
public:
    void fill(Field * field)
    {
        for (int i = 0; i < field->getHeight(); ++i) {
            for (int j = 0; j < field->getWidth(); ++j)
                if(rand() % x == 1 && flag == 0 && field->getCell(j, i)->getNumber()!=4 && field->getCell(j, i)->getNumber()!=5){
                    field->getCell(j, i)->clear();
                    field->setPlayerPosition(j, i);
                    field->getCell(j, i)->setPlayerHere(1);
                    flag+=1;
                    break;
                }
            if (!flag){
                field->getCell(1, 1)->clear();
                field->setPlayerPosition(1, 1);
                field->getCell(1, 1)->setPlayerHere(1);
            }
            break;
        }
    }
};
