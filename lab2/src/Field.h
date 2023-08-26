#pragma once

#include <vector>
#include "Cell.h"
//#include "Event.h"

class Field {
private:
    int width;
    int height;
    std::vector<std::vector<Cell>> cells;
    void createCells();
    int posX;
    int posY;
    int posKeyX;
    int posKeyY;
    int posExitX;
    int posExitY;
public:
    Field(int width, int height);

    Field();
    int getPosX() const;

    int getPosY() const;

    int getWidth() const;

    int getHeight() const;

    void setPlayerPosition(int x, int y);

    Cell* getCell(int x, int y);

    void updatePlayerPos(bool playerHere, int x, int y);

    void updateAvailable(bool available, int x, int y);

    Field(const Field &other);

    Field& operator=(const Field& other);

    Field(Field&& other) noexcept;

    Field& operator=(Field&& other);

};

