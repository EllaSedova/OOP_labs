#include <iostream>
#include "Field.h"
#include "FieldView.h"
#include "Player.h"
#include "Controller.h"
#include "Mediator.h"

int main() {
    Mediator mediator = Mediator();
    mediator.start();

    return 0;
}