#include "File_obs.h"

File_obs::File_obs(std::string fileName) {
    file.open(fileName, std::ios_base::out | std::ios_base::app );
}

void File_obs::update(int lvl,std::string str,Level* level) {
    if (file.is_open()) {
        Message message(str,lvl);
        file<<message;
        if(str=="End game")
            file << "____________________END LOG____________________"<<"\n";
        file.flush();

    }
}

File_obs::~File_obs() {

    file.close();
}