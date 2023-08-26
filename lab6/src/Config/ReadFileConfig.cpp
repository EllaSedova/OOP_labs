#include "ReadFileConfig.h"
ReadFileConfig::ReadFileConfig(std::string filename) {
    file.open(filename, std::ios_base::in);
}

void ReadFileConfig::readConfig() {
    if (!file.is_open()) {
        std::cout << "File isn't open!" << "\n";
        error = true;
    }
    else {
        while (getline(file, line)) {
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == '{' && !command_exist) {
                    int j = i + 1;
                    while (line[j] != '}' && j < line.size()) {
                        command += line[j];
                        j++;
                    }
                    if (line[j] == '}') {
                        std::list<std::string>::iterator iter = std::find(Prefix.begin(), Prefix.end(), command);
                        if (Prefix.end() == iter) {
                            std::cout << "Wrong prefix!" << std::endl;
                            //std::cout << pref << std::endl;
                            error = true;
                            command.clear();
                            break;
                        } else
                            command_exist = true;
                        count+=1;
                    }
                }
            for (int b = 0; b < line.size(); b++)
                if (line[b] == '[' && command_exist) {
                    if (line[b + 2] == ']') {
                        if (config.count(line[b + 1]) == 0) {
                            config[line[b + 1]] = command;
                        } else {
                            error = true;
                            command.clear();
                            break;
                        }
                    } else {
                        error = true;
                        command.clear();
                        break;
                    }
                    command.clear();
                    command_exist = false;
                }
            }
        }
    }
}


std::map <char, std::string>ReadFileConfig::getConfig() {
    if (count!=5){
        std::cout << "Not enough commands"<<"\n";
        error=true;
    }
    if (error){
        std::cout << "Default control set"<<"\n";
        return get_default();
    }
    else {
        return config;
    }
}

ReadFileConfig::~ReadFileConfig() {
    file.close();
}