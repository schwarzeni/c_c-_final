//
// Created by schwarzeni on 2019-03-16.
//

#ifndef BOOK_TASK_CPT_4_Q_27_H
#define BOOK_TASK_CPT_4_Q_27_H

#include <iostream>
#include <cmath>

// 二进制转十进制
namespace cpt_4_q_27 {
    void bTod() {
        long binary = 110011001011000110;
        int length = (int) std::log10((double) binary) + 1;
        int result = 0;

        for (int i = 1; i <= length; i++) {
            result += binary % 10 == 1 ? (long)std::pow(2, i - 1) : 0;
            binary = binary / 10;
        }

        std::cout << result << std::endl;
    }

    void func() {
        bTod();
    }
}

#endif //BOOK_TASK_CPT_4_Q_27_H
