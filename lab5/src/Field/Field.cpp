#include "Field.h"
#include "../Event/Key.h"
#include "../Event/Level_exit.h"
#include "../Event/Heal.h"
#include "../Event/Clear_cell.h"
#include "../Event/fire.h"
#include "../Event/Wall.h"


void Field::createCells() {
    cells.resize(height);
    for (int i = 0; i < height; ++i) {
        cells[i].resize(width);
        for (int j = 0; j < width; ++j) {
            if(getCell(j, i)->getNumber()==3 && !(getCell(j, i)->isPlayerHere()))
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

Field::Field(int width, int height) : width(width), height(height) {

    if (width<=0)
        this->width = -width;
    if (height <=0)
        this->height = -height;
    createCells();
}

Field * Field::CheckField(Field* field){
    int flag_key = 0;
    int flag_exit = 0;
    int flag_player = 0;
    for (int i = 0; i < field->getHeight(); ++i)
    {
        for (int j = 0; j < field->getWidth(); ++j)
        {
            if (field->getCell(j, i)->isPlayerHere() == 1)
            {flag_player += 1;
           // std::cout<<"flag_player:"<<flag_player<<'\n';
            }
            else if (field->getCell(j, i)->getNumber() == 4)
            { flag_key += 1;
            //    std::cout<<"flag_key:"<<flag_key<<'\n';
            }
            else if(field->getCell(j, i)->getNumber() == 5)
            { flag_exit += 1;
                //std::cout<<"flag_exit:"<<flag_exit<<'\n';
            }

        }
    }
    if (!(flag_key==1 &&  flag_exit==1 &&  flag_player==1)){
        setDefault(field);
    }
    return field;
}

void Field::setDefault(Field* field) {
std::cout<<"Default field"<<'\n';
    field->setHeight(10);
    field->setWidth(10);
    field->createCells();
    for (int i = 0; i < field->getHeight(); ++i) {
        for (int j = 0; j < field->getWidth(); ++j) {
            field->getCell(j, i)->clear();
            field->getCell(j, i)->setNumber(rand() % 4);
            field->getCell(j, i)->setPlayerHere(0);
            field->getCell(j, i)-> setDamage(20);
            field->getCell(j, i)-> setDamage(30);
            switch (field->getCell(j, i)->getNumber()) {
                case 0: {
                    field->getCell(j, i)->changeEvent(new Wall());
                    field->getCell(j, i)->setAvailable(0);
                    break;
                }
                case 1: {
                    field->getCell(j, i)->changeEvent(new fire());
                    break;
                }
                case 2: {
                    field->getCell(j, i)->changeEvent(new Heal());
                    break;
                }
            }
        }
    }
    field->getCell(0,0)->clear();
    field->setPlayerPosition(0, 0);
    field->getCell(0, 0)->setPlayerHere(1);
    field->getCell(1,1)->clear();
    field->getCell(1, 1)->setNumber(4);
    field->getCell(1, 1)->changeEvent(new Key());
    field->getCell(2,2)->clear();
    field->getCell(2, 2)->setNumber(5);
    field->getCell(2, 2)->changeEvent(new Level_exit());
   // return field;
}


int Field::getPosX() const {
    return posX;
}

int Field::getPosY() const {
    return posY;
}

void Field::setWidth(int width) {
    Field::width = width;
}

void Field::setHeight(int height) {
    Field::height = height;
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
