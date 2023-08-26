#include "Subject.h"
void Subject::addObs(Observer * obs) {
    observers.push_back(obs);

}

void Subject::notify(int lvl, std::string str, Level* level) {
    switch (lvl) {
        case 1: {
            if (level->getInfo()) {
                for (auto &observer: observers) {
                    observer->update(lvl, str,level);
                }

            }
            break;
        }
        case 2: {
            if (level->getStatement()) {
                for (auto &observer: observers) {
                    observer->update(lvl, str,level);
                }
            }
            break;
        }
        case 3: {
            if (level->getError()) {
                for (auto &observer: observers) {
                    observer->update(lvl, str,level);
                }
            }
            break;
        }
    }
}