#include <iostream>
#include "FieldView.h"
#include <typeinfo>
FieldView::FieldView(Field *field): field(field) {}

void FieldView::printField() {
    for (int i = 0; i < field->getHeight(); ++i) {
        for (int j = 0; j < field->getWidth(); ++j) {
            if (field->getCell(j, i)->isPlayerHere())
                std::cout << 'P' << ' ';
            else {
                int a = field->getCell(j, i)->getNumber();
                switch(a){
                    case 0:{
                        std::cout << '#' << ' ';
                        break;
                    }
                    case 1:{
                        std::cout << 'F' << ' ';
                        break;
                    }
                    case 2:{
                        std::cout << '+' << ' ';
                        break;
                    }
                    case 3:{
                        std::cout << '.' << ' ';
                        break;
                    }
                    case 4:{
                        std::cout << 'K' << ' ';
                        break;
                    }
                    case 5:{
                        std::cout << 'E' << ' ';
                        break;
                    }
                }
            }
        }
        std::cout << '\n';

    }
    std::cout << '\n';
}
