#include "Console_obs.h"


void Console_obs::update(int lvl, std::string str,Level* level){
    Message message(str,lvl);
    std::cout<<message;
    //std::cout << getPrefix(lvl) << str << "\n";
}
