//#pragma once
//
//#include "Field.h"
//#include "Heal.h"
//
//template <int heals>
//class EventRule
//        {
//public:
//    void fill(Field * field)
//    {
//        for (int k = 0; k < abs(heals); k++)
//        {
//            int i = rand()%field->getHeight();
//            int j = rand()%field->getWidth();
//                if ((field->getCell(j, i)->getNumber())==3 && (field->getCell(j, i)->isPlayerHere())==0)
//                {
//                    field->getCell(j, i)->changeEvent(new Heal());
//                    field->getCell(j, i)->setNumber(2);
//                }
//        }
//    }
//};
#pragma once

#include "Field.h"
#include "Heal.h"
#include "fire.h"
#include "Wall.h"

template <unsigned int event,unsigned int count>
class EventRule
{
private:
    int n;
public:

    void fill(Field * field)
    {
        n = field->getHeight() * field->getWidth();
        if (count>n)
            n = count%n;
        else
            n = count;
        for (int k = 0; k < n; k++)
        {
            int i = rand()%field->getHeight();
            int j = rand()%field->getWidth();
            if ((field->getCell(j, i)->getNumber())==3 && (field->getCell(j, i)->isPlayerHere())==0)
            {
                if (event==0)
                {
                    field->getCell(j, i)->changeEvent(new Wall());
                    field->getCell(j, i)->setNumber(0);
                    field->getCell(j, i)->setAvailable(0);
                }
                if (event==1)
                {
                    field->getCell(j, i)->changeEvent(new fire());
                    field->getCell(j, i)->setNumber(1);
                }
                if (event==2)
                {
                field->getCell(j, i)->changeEvent(new Heal());
                field->getCell(j, i)->setNumber(2);
                }
            }
        }
    }
};
