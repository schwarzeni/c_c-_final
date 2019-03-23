//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_10_H
#define PLAYGROUND_CPT21_10_H

#include <iostream>

// 计算乘方
namespace book_task_q_cpt21_10 {
    void showDigit(unsigned value) {
        std::cout << value << " ";
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

    int power2(int number, int pow) {
        return number << pow;
    }

    void func() {
        int data = 10;
        showDigit(data);
        data = power2(data, 3);
        showDigit(data);
    }
}

#endif //PLAYGROUND_CPT21_10_H
