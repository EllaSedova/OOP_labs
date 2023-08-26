#include "Message.h"
Message::Message(std::string m, int l): msg(m),lvl(l) {}

std::ostream& operator<<(std::ostream &out, const Message& d) {
    return out<<d.getPrefix(d.lvl)<<" " <<d.getMsg()<< "\n";
}

std::string Message::getPrefix(int lvl) const{
    switch (lvl) {
        case 1: {
            return "[INFO]";
            break;
        }
        case 2: {
            return "[STATEMENT]";
            break;
        }
        case 3: {
            return "[ERROR]";
            break;
        }
    }

}

std::string Message::getMsg() const{
    return msg;
}