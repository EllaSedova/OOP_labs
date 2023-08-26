#pragma once

#include <vector>
#include "../Cell/Cell.h"


class Field{
private:
    int width = -1;
    int height = -1;
    std::vector<std::vector<Cell>> cells;
    std::vector<std::vector<int>> arr;
//int** arr;
    int posX;
    int posY;
    size_t hashFieldfile =0;
    size_t hashField=0;


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
    void saveField(std::string fileName);
    void reloadField(std::string fileName);
    void del(int* mas,std::string line);
    void recoverCell(int x, int y, int number);
    void reloadCorrectState();
    bool isEqual(size_t a,size_t b);
    size_t gethashFieldfile() const;
    size_t gethashField() const;
};