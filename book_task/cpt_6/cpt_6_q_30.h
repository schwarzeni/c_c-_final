//
// Created by schwarzeni on 2019-03-17.
//

#ifndef BOOK_TASK_CPT_6_Q_11_H
#define BOOK_TASK_CPT_6_Q_11_H

#include <iostream>
#include <cmath>

namespace cpt_6_q_30 {
    void func() {
        int data = 3254;
        int result = 0;

        while (data > 0) {
            result *= 10;
            result += data % 10;
            data /= 10;
        }

        std::cout << result << std::endl;
    }
}

#endif //BOOK_TASK_CPT_6_Q_11_H
