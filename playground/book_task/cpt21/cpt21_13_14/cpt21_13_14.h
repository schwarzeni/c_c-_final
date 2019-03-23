//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_13_14_H
#define PLAYGROUND_CPT21_13_14_H

#include <iostream>

namespace book_task_q_cpt21_13_14 {
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
        int firstNum;
        int secNum;
        int thirdNum;
        int forthNum;
        // 00000000 00000000 00000000 11111111
        int mask = 255;
        forthNum = data & mask;
        data >>= 8;
        thirdNum = data & mask;
        data >>= 8;
        secNum = data & mask;
        data >>= 8;
        firstNum = data & mask;

        std::cout << "[1] " << firstNum << std::endl;
        std::cout << "[2] " << secNum << std::endl;
        std::cout << "[3] " << thirdNum << std::endl;
        std::cout << "[4] " << forthNum << std::endl;

        std::cout << "[finish] unpack digit ........" << std::endl;
    }

    unsigned packDigit(int firstNum, int secNum, int thirdNum, int forthNum) {
        std::cout << "start pack digit ........" << std::endl;
        unsigned data = 0;

        data = data | firstNum;
        data <<= 8;
        data = data | secNum;
        data <<= 8;
        data = data | thirdNum;
        data <<= 8;
        data = data | forthNum;

        printDigit(data);

        std::cout << "[finish] pack digit ........" << std::endl;
        return data;
    }

    void func() {
        int firstNum;
        int secNum;
        int thirdNum;
        int forthNum;

        std::cin >> firstNum >> secNum >> thirdNum >> forthNum;
        const unsigned i = packDigit(firstNum, secNum, thirdNum, forthNum);
        unPackDigit(i);
    }

}
#endif //PLAYGROUND_CPT21_13_14_H
