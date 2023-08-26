#pragma once
#include "Field.h"

template <unsigned int x>
class DamageRule {
public:
    void fill(Field * field)
    {
        for (int i = 0; i < field->getHeight(); ++i)
        {
            for (int j = 0; j < field->getWidth(); ++j)
                field->getCell(j, i)->setDamage(x);
        }
    }
};