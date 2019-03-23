//
// Created by schwarzeni on 2019-03-22.
//

#ifndef PRACTICE_TASK_2013_10_H
#define PRACTICE_TASK_2013_10_H

#include <iostream>
#include <iomanip>

namespace task_2013_10 {
    void func() {
        const int kMin = 33;
        const int kMax = 126;

        const std::ios::fmtflags flag = std::cout.flags();

        for (int i = kMin; i <= kMax; i++) {
            std::cout.flags(flag);
            std::cout << std::showpos << std::setw(15) << std::right << i;
            std::cout << std::showbase << std::setw(15) << std::right << std::hex << i;
            std::cout << std::showbase << std::setw(15) << std::right << std::oct << i;
            std::cout << std::setw(15) << std::right << static_cast<char> (i);
            std::cout << std::endl;
        }
    }
}

#endif //PRACTICE_TASK_2013_10_H
