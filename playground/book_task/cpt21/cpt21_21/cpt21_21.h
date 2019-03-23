//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_21_H
#define PLAYGROUND_CPT21_21_H

#include <iostream>
#include <cstdlib>

namespace book_task_q_cpt21_21 {
    void func() {
        char num1[10];
        char num2[10];
        char num3[10];
        char num4[10];
        std::cin >> num1 >> num2 >> num3 >> num4;

        int count = 0;
        count += std::atoi(num1);
        count += std::atoi(num2);
        count += std::atoi(num3);
        count += std::atoi(num4);

        std::cout << count << std::endl;
    }
}

#endif //PLAYGROUND_CPT21_21_H
