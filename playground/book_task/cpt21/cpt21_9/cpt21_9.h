//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_9_H
#define PLAYGROUND_CPT21_9_H

#include <iostream>

// 右移字符串
namespace book_task_q_cpt21_9 {
    void printDigit(unsigned value) {
        int size = 8 * (sizeof(unsigned));
        std::string output;

        for (int i = 1; i <= size; i++) {
            value & 1 ? output.insert(0, "1") : output.insert(0, "0");

            if (i % 8 == 0 && i != size) {
                output.insert(0, 1, ' ');
            }

            value >>= 1;
        }

        std::cout << output << std::endl;
    }

    void func() {
        int digit = 10;
        printDigit(digit);
        digit >>= 4;
        printDigit(digit);
    }
}

#endif //PLAYGROUND_CPT21_9_H
