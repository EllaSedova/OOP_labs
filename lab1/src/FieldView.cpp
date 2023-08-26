#include <iostream>
#include "FieldView.h"

FieldView::FieldView(Field *field): field(field) {}

void FieldView::printField() {
    for (int i = 0; i < field->getHeight(); ++i) {
        for (int j = 0; j < field->getWidth(); ++j) {
            if (field->getCell(j,i).isPlayerHere())
                std::cout << 'P' << ' ';
            else{
                if(field->getCell(j,i).isAvailable())
                    std::cout << '_' << ' ';
                else
                    std::cout << '$' << ' ';
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}