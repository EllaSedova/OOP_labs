#pragma once
#include "Field.h"

template <unsigned int x, unsigned int y>
class FieldSizeRule {
public:
    void fill(Field * field) {
        if (x < 3 || y < 3) {
            field->setHeight(3);
            field->setWidth(3);
            field->createCells();
        } else{
        field->setHeight(y);
        field->setWidth(x);
        field->createCells();
        }
    }
};
