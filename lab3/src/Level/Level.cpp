#include "Level.h"
#include <iostream>

Level::Level() {
    std::string l;
    std::cout << "Include INFO? [y/n]" << "\n";
    std::cin >> l;
    if (l == "y") {
        info=true;
    }
    std::cout << "Include STATEMENT? [y/n]" << "\n";
    std::cin >> l;
    if (l == "y") {
        statement= true;
    }
    std::cout << "Include ERROR? [y/n]" << "\n";
    std::cin >> l;
    if (l == "y") {
        error = true;
    }
    std::cout << "Write to the console? [y/n]" << "\n";
    std::cin >> l;
    if (l == "y") {
        console = true;
    }
    std::cout << "Write to a file? [y/n]" << "\n";
    std::cin >> l;
    if (l == "y") {
        file = true;
    }
}

bool Level::toConsole() const {
    return console;
}
bool Level::toFile() const {
    return file;
}
bool Level::getInfo() const {
    return info;
}
bool Level::getStatement() const {
    return statement;
}
bool Level::getError() const {
    return error;
}