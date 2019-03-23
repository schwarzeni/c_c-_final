//
// Created by 倪震洋 on 2019-03-07.
//

#ifndef PLAYGROUND_QUZE2_H
#define PLAYGROUND_QUZE2_H

#include <string>
#include <chrono>
#include <iostream>

struct Shiyanlou {
    std::string description;

    friend std::ostream &operator<<(std::ostream &os, const Shiyanlou &shiyanlou) {
        os << shiyanlou.description;
        return os;
    }
};

// TODO START
template<typename T, typename... Args>
std::ostream &_print(std::ostream &os, T& t) {
    return os << t << "\n";
}

template<typename T, typename... Args>
std::ostream &_print(std::ostream &os, T &t, Args... args) {
    os << t << "\n";
    return _print(os, args...);
}

template<typename T, typename... Args>
void shiyanlou_printf(T value, Args... args) {
    _print(std::cout, value, args...);
}

void func_quze_1_2() {
    Shiyanlou shiyanlou{"Learn by Doing"};

    auto t1 = std::chrono::high_resolution_clock::now();

    shiyanlou_printf(1, 2, 3.14, 5, 6, 7, 8, 9, 10, 11, 12, 13, "Shiyanlou C++ Contest", std::move(shiyanlou));
//    shiyanlou_printf(1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13);

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << duration << std::endl;
}
// TODO END

#endif //PLAYGROUND_QUZE2_H
