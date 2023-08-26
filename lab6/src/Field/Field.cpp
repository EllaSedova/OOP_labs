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


void Field::saveField(std::string fileName) {
    std::ofstream file;
    file.open(fileName);
    int count = 0;
    if (file.is_open()) {
        file<<height<<'|'<<width<<'\n';
        for (int i = 0; i < height; i++){
                for (int j = 0; j < width; ++j) {
                    if (getCell(j, i)->isPlayerHere()) {
                        file << 8;
                        count += 8;
                    } else {
                    file << getCell(j, i)->getNumber();
                    count+=getCell(j, i)->getNumber();
                }
                    }
            file << std::endl;
                }

        }
    hashField = std::hash<std::string>()(std::to_string(count));
        //file.flush();
        file.close();

}
void Field::del(int* mas,std::string line){
    std::string delim = "|";
    auto start = 0U;
    auto end = line.find(delim);
    int i=0;
    while (end != std::string::npos){
                mas[i]=std::stoi(line.substr(start, end - start));
                start = end + delim.length();
                end = line.find(delim, start);
                i++;
            }
    mas[i] = std::stoi(line.substr(start, end));


}

void Field::reloadField(std::string fileName) {
    std::fstream file;
    std::string line;
    int count = 0;
    int mas[2];
    file.open(fileName);
    if (file.is_open(), std::ios_base::in) {
        getline(file, line);
        del( mas,line);
        int y = mas[0];
        int x = mas[1];
        //int arr[y][x];
        arr.resize(y);
        for (int t = 0; t < x; ++t) {
            arr[t].resize(y);}

        int i = 0;
        while (getline(file, line)) {
                for (int j = 0; j < x; j++) {
                    arr[i][j] = (int)(line[j])-48;
                    count += arr[i][j];
                }
                i++;
            }
        hashFieldfile = std::hash<std::string>()(std::to_string(count));
        file.close();
        if (!isEqual(hashFieldfile,hashField))
            throw "Can't reload field!";
        reloadCorrectState();



    }
}
void Field::reloadCorrectState() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            getCell(j, i)->setPlayerHere(0);
            if ((getCell(j, i)->getNumber()) != (arr[i][j])) {

//                    std::cout << "Number: " << getCell(j, i)->getNumber() << '\n';
//                    std::cout << "arr: " << arr[i][j] << '\n';
//                    std::cout << "x: " << j << "y: " << i << '\n';
                recoverCell(i, j, arr[i][j]);
            }
        }
    }
}
void Field::recoverCell(int y, int x, int number) {
    switch(number){
    case 0: {
        getCell(x, y)->changeEvent(new Wall());
        getCell(x, y)->setAvailable(0);
        getCell(x, y)->setNumber(0);
        break;
    }
    case 1: {
        getCell(x, y)->changeEvent(new fire());
        getCell(x, y)->setNumber(1);
        break;
    }
    case 2: {
        getCell(x, y)->changeEvent(new Heal());
        getCell(x, y)->setNumber(2);
        break;
    }
        case 3: {
            getCell(x, y)->changeEvent(new Clear_cell());
            getCell(x, y)->setNumber(3);
            break;
        }
    case 4: {
        getCell(x, y)->changeEvent(new Key());
        getCell(x, y)->setNumber(4);
        break;
    }
    case 5:{
        getCell(x, y)->changeEvent(new Level_exit());
        getCell(x, y)->setNumber(5);
        break;
    }
    case 8: {
        setPlayerPosition(x, y);
        getCell(x, y)->setPlayerHere(1);
        getCell(x, y)->clear();
        break;
            }
    }
}
bool Field::isEqual(size_t a,size_t b){
    if ((hashFieldfile == hashField) ||(hashField==0))
        return 1;
    else return 0;
}
size_t Field::gethashField() const{
    return hashField;
}
size_t Field::gethashFieldfile() const {
return hashFieldfile;
}