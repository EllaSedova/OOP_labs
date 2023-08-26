#include "Field.h"

void Field::createCells() {
    cells.resize(height);
    for (int i = 0; i < height; ++i) {
        cells[i].resize(width);
        for (int j = 0; j < width; ++j) {
            cells[i][j] = Cell();
        }
    }
}

int Field::getWidth() const {
    return width;
}

int Field::getHeight() const {
    return height;
}

Field::Field(): width(4), height(4), posX(0), posY(0)  {
    createCells();
    cells[posY][posX].setPlayerHere(true);
}

Field::Field(int width, int height) : width(width), height(height), posX(0), posY(0) {
    if (width<=0)
        this->width = -width;
    if (height <=0)
        this->height = -height;
    createCells();
    cells[posY][posX].setPlayerHere(true);
}

int Field::getPosX() const {
    return posX;
}

int Field::getPosY() const {
    return posY;
}

void Field::setPlayerPosition(int x, int y) {
    posX = x;
    posY = y;
}

Cell Field::getCell(int x, int y) {
    return cells[y][x];
}

void Field::updatePlayerPos(bool playerHere, int x, int y) {
    cells[y][x].setPlayerHere(playerHere);
}

void Field::updateAvailable(bool available, int x, int y) {
    cells[y][x].setAvailable(available);
}
// конструктор копирования
Field::Field(const Field &other) {
    this->width = other.width;
    this->height = other.height;
    this->posX = other.posX;
    this->posY = other.posY;
    this->cells = other.cells;
}
// оператор присваивания
Field &Field::operator=(const Field &other) {
    if (this)
        delete this;
    this->width = other.width;
    this->height = other.height;
    this->posX = other.posX;
    this->posY = other.posY;
    this->cells = other.cells;
    return *this;
}
// конструктор перемещения
Field::Field(Field &&other) noexcept {
    this->width = other.width;
    this->height = other.height;
    this->posX = other.posX;
    this->posY = other.posY;
    this->cells = std::move(other.cells);
}
// оператор присваивания с перемещением
Field &Field::operator=(Field &&other) {
    if (this)
        delete this;
    this->width = other.width;
    this->height = other.height;
    this->posX = other.posX;
    this->posY = other.posY;
    this->cells = std::move(other.cells);
    return *this;
}


