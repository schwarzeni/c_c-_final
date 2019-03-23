//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT18_Q_TASK_23_H
#define PLAYGROUND_CPT18_Q_TASK_23_H

#include <iostream>

namespace cpt18_q_task_23 {
    void func() {
        std::string str = "1234567890";
        str.erase(str.cbegin() + 1, str.cend() - 1);
        std::cout << str << std::endl;
    }
}

#endif //PLAYGROUND_CPT18_Q_TASK_23_H
