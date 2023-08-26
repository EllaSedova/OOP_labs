#pragma once
#include <string>
#include <iostream>
#include"EventPlayer.h"
class Heal : public EventPlayer {
public:
    void make_event(Player& player, Cell& cell);
};





















//#pragma once
//
//#include "Event.h"
//#include "EventPlayer.h"
//
//class HealthDownEvent: public StatsEvent{
//public:
//    std::string doEvent(Player *player) override;
//
//    HealthDownEvent(int value);
//};
//
//







//class IntDerived : public IntTypeEvent {
//public:
//    explicit IntDerived(int value) : IntTypeEvent(value) {}
//
//    void invoke() override {
//        std::cout << "Int Derived : " + std::to_string(_value) + '\n';
//    }
//};