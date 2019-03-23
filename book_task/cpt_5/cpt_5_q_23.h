//
// Created by schwarzeni on 2019-03-16.
//

#ifndef BOOK_TASK_CPT_5_Q_23_H
#define BOOK_TASK_CPT_5_Q_23_H

#include <iostream>

namespace cpt_5_q_23 {
    void func() {
        int size = 31;
        int half = size / 2;

        for (int level = 1; level <= size; level++) {
            if (level <= half) {
                for (int width = level - 1; width < half; width++) {
                    std::cout << " ";
                }
                for (int width = 0; width < level * 2 - 1; width++) {
                    std::cout << "*";
                }
            } else {
                for (int width = 0; width < level - half - 1; width++) {
                    std::cout << " ";
                }
                for (int width = 0; width < (size - level) * 2 + 1; width++) {
                    std::cout << "*";
                }
            }
            std::cout << std::endl;
        }
    }
}

#endif //BOOK_TASK_CPT_5_Q_23_H
