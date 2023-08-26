#pragma once
#include <iostream>
#include <random> // для std::mt19937
#include <ctime>  // для std::time
#include <algorithm>
class Randomizer {
public:
    static int random(int x){
        // Инициализируем наш вихрь Мерсенна случайным начальным значением на основе часов
        std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
// Создаем многоразовый генератор случайных чисел,
//  который равномерно генерирует числа от 1 до x
        std::uniform_int_distribution<> die{ 0, x };
// Распечатываем пачку случайных чисел
        return int(die(mersenne));  // здесь генерируем результат броска кубика
    }
};



