#pragma once

#include <vector>
#include "../Cell/Cell.h"


class Field{
private:
    int width = -1;
    int height = -1;
    std::vector<std::vector<Cell>> cells;


    int posX;
    int posY;


public:
    void createCells();
    Field(int width, int height);
    int getPosX() const;

    int getPosY() const;

    int getWidth() const;

    int getHeight() const;
    void setWidth(int x);

    void setHeight(int y);

    Field * CheckField(Field* field);
    void setDefault(Field* field);

    void setPlayerPosition(int x, int y);

    Cell* getCell(int x, int y);

    void updatePlayerPos(bool playerHere, int x, int y);

    void updateAvailable(bool available, int x, int y);

    Field(const Field &other);

    Field& operator=(const Field& other);

    Field(Field&& other) noexcept;

    Field& operator=(Field&& other);

};