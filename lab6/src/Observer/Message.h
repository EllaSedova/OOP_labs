#pragma once
#include <string>
#include <iostream>
class Message {
    friend std::ostream& operator<<(std::ostream &out, const Message& d);
public:
    std::string msg;
    int lvl;
    Message(std::string m,int l);
    std::string getPrefix(int lvl) const;
    std::string getMsg() const;

};
