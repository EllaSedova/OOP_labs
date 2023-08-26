#include <iostream>
#include "Field/Field.h"
#include "Field/FieldView.h"
#include "Controller/Controller.h"
#include "Mediator/Mediator.h"

int main() {
    Mediator mediator = Mediator();
    mediator.start();
    return 0;
}
