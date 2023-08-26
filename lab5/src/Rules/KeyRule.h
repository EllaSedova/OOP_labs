#pragma once
#include "Field.h"
#include "Key.h"

template <unsigned int x>
class KeyRule
{
private:
    int flag = 0;
public:
    void fill(Field * field)
    {
            for (int i = 0; i < field->getHeight(); ++i)
            {
                for (int j = 0; j < field->getWidth(); ++j)
                    if(rand() % x == 0 && (field->getCell(j, i)->isPlayerHere())==0 && flag == 0 && field->getCell(j, i)->getNumber()!=5)
                    {
                        field->getCell(j, i)->clear();
                        field->getCell(j, i)->changeEvent(new Key());
                        field->getCell(j, i)->setNumber(4);
                        flag+=1;
                        break;
                    }
                if (!flag)
                {
                    field->getCell(0, 0)->clear();
                    field->getCell(0, 0)->changeEvent(new Key());
                    field->getCell(0, 0)->setNumber(4);
                }
                break;
            }
    }
};
