//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_22_H
#define PLAYGROUND_CPT21_22_H

#include <iostream>
#include <cstdlib>
#include <iomanip>

// 四个浮点数相加
namespace book_task_q_cpt21_22 {
    void func() {
        char num1[10];
        char num2[10];
        char num3[10];
        char num4[10];

        std::cin >> num1 >> num2 >> num3 >> num4;

        double count = 0;
        count += std::strtod(num1, nullptr);
        count += std::strtod(num2, nullptr);
        count += std::strtod(num3, nullptr);
        count += std::strtod(num4, nullptr);

        std::cout << std::fixed << std::setprecision(2) << count << std::endl;
    }
}

#endif //PLAYGROUND_CPT21_22_H
