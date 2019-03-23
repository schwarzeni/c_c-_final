//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_15_H
#define PLAYGROUND_CPT21_15_H

#include <iostream>

namespace book_task_q_cpt21_15 {
    void printDigit(unsigned value) {
        std::string resultStr;
        int size = 8 * (sizeof(unsigned));

        for (int i = 1; i <= size; i++) {
            resultStr.insert(0, value & 1 ? "1" : "0");
            value >>= 1;
            if (i % 8 == 0 && i != size) {
                resultStr.insert(0, 1, ' ');
            }
        }
        std::cout << resultStr << std::endl;
    }

    unsigned reverseBits(unsigned value) {
        unsigned newValue = 0;
        int size = 8 * (sizeof(unsigned));
        int mask = 1 << (size - 1);
        int mask2 = 1;
        for (int i = 1; i <= size; i++) {
            bool isBit = (value & mask) != 0;
            if (isBit) {
                newValue = mask2 | newValue;
            }
            mask2 <<= 1;
            value <<=1;
        }
        return newValue;
    }

    void func() {
        int data = (1 << 31) + 82193;
//        std::cin >> data;
        printDigit(data);
        data = reverseBits(data);
        printDigit(data);
    }
}

#endif //PLAYGROUND_CPT21_15_H
