//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT18_Q_TASK_21_H
#define PLAYGROUND_CPT18_Q_TASK_21_H

#include <iostream>

namespace cpt18_q_task_21 {
    void func() {
        std::string s;
        std::cout << "Please enter a string: " << std::endl;

        std::getline(std::cin, s, '\n');

        std::string::reverse_iterator rb = s.rbegin();

        while (rb != s.rend()) {
            std::cout << *rb;
            ++rb;
        }
        std::cout << std::endl;
    }
}

#endif //PLAYGROUND_CPT18_Q_TASK_21_H
