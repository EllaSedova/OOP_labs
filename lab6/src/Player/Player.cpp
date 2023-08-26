#include "Player.h"

#include <utility>// для move(name)

Player::Player(int healthPoint, int damage, int armor, std::string name, bool key, bool exit) :
        healthPoint(healthPoint), damage(damage), armor(armor), name(std::move(name)), key(key), exit(exit) {

}

Player::Player(Level* level): healthPoint(100), damage(0), armor(100), name(std::string("Bebra")), key(false), exit(false){

    if (level->toConsole())
        addObs(new Console_obs);
    if (level->toFile())
        addObs(new File_obs("out.txt"));
}

int Player::getHealthPoint() const {
    return healthPoint;
}

void Player::setHealthPoint(int healthPoint,Level* level) {
    Player::healthPoint = healthPoint;

    notify(1,"Change HP",level);

}
bool Player::getKey() const {
    return key;
}
void Player::setKey(bool key,Level* level) {
    Player::key = key;
    notify(1,"Get key",level);
}
bool Player::getExit() const {
    return exit;
}
void Player::setExit(bool exit,Level* level) {
    Player::exit = exit;
    //notify(1,"Exit",level);
}

int Player::getDamage() const {
    return damage;
}

void Player::setDamage(int damage) {
    Player::damage = damage;
}

int Player::getArmor() const {
    return armor;
}

void Player::setArmor(int armor,Level* level) {
    Player::armor = armor;
    notify(1,"Change armor",level);
}


std::string Player::getName() const {
    return name;
}

void Player::setName(const std::string &name) {
    Player::name = name;
}
void Player::savePlayer(std::string fileName) {
    std::ofstream file;
    file.open(fileName);
    hashPlayer = std::hash<std::string>()(std::to_string(healthPoint + armor + key));
    if (file.is_open()) {
        file<<this->healthPoint<<"|"<<this->armor<<"|"<<this->key<<'\n';
        //file.flush();
        file.close();
    }
}
bool Player::isDigit(std::string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
   //if (*p == 0)
   //     throw "Not digit!";
    //std::cout<<p<<'\n';
    return *p == 0;
}


void Player::del(std::string line){
    std::string delim = "|";
    auto start = 0U;
    auto end = line.find(delim);
    int i=0;
    while (end != std::string::npos){
        std::string o = line.substr(start, end - start);

        try {
            bool z = isDigit(o);
            if (z == 0)
            {
                throw "Not digit!";
            }
        }
        catch (const char* msg) {
            std::cerr << msg << std::endl;
            er+=1;
        }
        mas.at(i) = std::stoi(o);
                //mas[i]=std::stoi(o);
        //mas.push_back(std::stoi(o));
                start = end + delim.length();
                end = line.find(delim, start);
                i++;
            }
    mas.at(i) =  std::stoi(line.substr(start, end));
    //mas.push_back(std::stoi(line.substr(start, end)));
    //mas[i] = std::stoi(line.substr(start, end));


}

void Player::reloadPlayer(std::string fileName) {
    std::fstream file;
    std::string line;
    //mas.resize(3);
    //int mas[3];
    file.open(fileName);
    if (file.is_open(), std::ios_base::in) {
        while (getline(file, line)) {
            del(line);
        }
//
        hashPlayerfile = std::hash<std::string>()(std::to_string(mas[0] + mas[1] +mas[2]));
        file.close();
        if (!isEqual(hashPlayerfile,hashPlayer)){
            throw "Can't reload player!";
            }
        reloadCorrectState();



    }
}
void Player::reloadCorrectState() {
    healthPoint = mas[0];
    armor = mas[1];
    key = mas[2];
}
bool Player::isEqual(size_t a,size_t b){
    if ((hashPlayerfile == hashPlayer)||(hashPlayer==0))
        return 1;
    else return 0;
}
size_t Player::gethashPlayer() const{
    return hashPlayer;
}
size_t Player::gethashPlayerfile() const {
    return hashPlayerfile;
}