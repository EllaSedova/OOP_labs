#include "Field.h"
#include "../Event/Key.h"
#include "../Event/Level_exit.h"


void Field::createCells(Level* level) {
    cells.resize(height);
    for (int i = 0; i < height; ++i) {
        cells[i].resize(width);
        for (int j = 0; j < width; ++j) {
            cells[i][j] = Cell();
            if (level->toConsole())
                cells[i][j].event->addObs(new Console_obs);
            if (level->toFile())
                cells[i][j].event->addObs(new File_obs("out.txt"));

        }
    }
}

int Field::getWidth() const {
    return width;
}

int Field::getHeight() const {
    return height;
}

Field::Field(int width, int height, Level* level) : width(width), height(height), posX(0), posY(0), posKeyX(1), posKeyY(1), posExitX(2), posExitY(2) {
    if (level->toConsole())
    addObs(new Console_obs);
    if (level->toFile())
    addObs(new File_obs("out.txt"));

    if (width<=0 || height<=0 ){
        notify(3,"Wrong size",level);
    }
    if (width<=0)
        this->width = -width;
    if (height <=0)
        this->height = -height;
    createCells(level);
    cells[posY][posX].clear();
    cells[posY][posX].setPlayerHere(true);
    cells[posKeyX][posKeyY].clear();
    cells[posKeyX][posKeyY].event = new (Key);
    if (level->toConsole())
    cells[posKeyX][posKeyY].event->addObs(new Console_obs);
    if (level->toFile())
    cells[posKeyX][posKeyY].event->addObs(new File_obs("out.txt"));
    cells[posExitX][posExitY].clear();
    cells[posExitX][posExitY].event = new (Level_exit);
    if (level->toConsole())
    cells[posExitX][posExitY].event->addObs(new Console_obs);
    if (level->toFile())
    cells[posExitX][posExitY].event->addObs(new File_obs("out.txt"));
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

Cell* Field::getCell(int x, int y) {
    return &cells[y][x];
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

