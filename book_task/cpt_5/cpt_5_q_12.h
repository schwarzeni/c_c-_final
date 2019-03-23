//
// Created by schwarzeni on 2019-03-16.
//

#ifndef BOOK_TASK_CPT_5_Q_12_H
#define BOOK_TASK_CPT_5_Q_12_H

#include <iostream>
#include <iomanip>

namespace cpt_5_q_12 {
    void func() {
        for (int level = 0; level < 10; level++) {
            for (int pic1 = 0; pic1 < 10; pic1++) {
                std::cout << "*";
                if (pic1 == level)break;
            }
            std::cout << std::setw(10 - level);

            for (int pic2 = 0; pic2 < 10; pic2++) {
                std::cout << "*";
                if (10 - pic2 -1 == level) break;
            }

            std::cout << std::setw(level + 1);

            for (int pic3 = 0; pic3 < 10; pic3++) {
                if (pic3 < level) {
                    std::cout << " ";
                } else {
                    std::cout << "*";
                }
            }

            for (int pic4 = 0; pic4 < 10; pic4++) {
                if (10 - pic4 - 1 > level) {
                    std::cout << " ";
                } else {
                    std::cout << "*";
                }
            }

            std::cout << std::endl;
        }
    }
}

#endif //BOOK_TASK_CPT_5_Q_12_H
