#pragma once

#include "Field.h"

class FieldView {
private:
    Field* field;
public:
    void printField();

    FieldView(Field* field);
};
