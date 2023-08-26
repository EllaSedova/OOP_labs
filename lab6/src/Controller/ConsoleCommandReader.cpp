#include "ConsoleCommandReader.h"

char ConsoleCommandReader::readCommand() {
    std::cin >> ch;
    return ch;
}


















//ConsoleCommandReader::ConsoleCommandReader() {
//
//    ReadFileConfig read_conf("ReadConfig.txt");
//    read_conf.readConfig();
//    conf = read_conf.getConfig();
//}

//std::string ConsoleCommandReader::readCommand(){
//    std::cin >> user_input;
//    return conf[user_input];
//}