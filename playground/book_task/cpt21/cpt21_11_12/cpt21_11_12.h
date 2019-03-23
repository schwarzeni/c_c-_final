//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_11_H
#define PLAYGROUND_CPT21_11_H

#include <iostream>

namespace book_task_q_cpt21_11_12 {

    void printDigit(unsigned value) {
        std::string resultStr;
        int size = 8 * (sizeof(value));

        for (int i = 1; i <= size; i++) {
            resultStr.insert(0, value & 1 ? "1" : "0");
            value >>= 1;
            if (i % 8 == 0 && i != size) {
                resultStr.insert(0, 1, ' ');
            }
        }
        std::cout << resultStr << std::endl;
    }

    void unPackDigit(unsigned data) {
        std::cout << "start unpack digit ........" << std::endl;
        // 1111 1111 0000 0000
        int firstMask = 65280;
        int firstValue = (firstMask & data) >> 8;
        std::cout << "first value: " << firstValue << " ";
        // 0000 0000 1111 1111
        int secMask = 255;
        int secValue = secMask & data;
        std::cout << "second value: " << secValue << std::endl;

        std::cout << "[finish] unpack digit ........" << std::endl;
    }

    unsigned packDigit(int firstNum, int secNum) {
        std::cout << "start pack digit ........" << std::endl;
        printDigit(firstNum);
        printDigit(secNum);

        firstNum <<= 8;
        unsigned result = firstNum | secNum;

        printDigit(result);
        std::cout << "[finish] pack digit ........" << std::endl;
        return result;
    }

    void func() {
        int firstNum, secNum;
        std::cin >> firstNum >> secNum;
        const unsigned data = packDigit(firstNum, secNum);
        unPackDigit(data);
    }
}

#endif //PLAYGROUND_CPT21_11_H
