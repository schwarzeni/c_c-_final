//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT18_Q_TASK_8_H
#define PLAYGROUND_CPT18_Q_TASK_8_H

#include <iostream>

// 迭代器的使用 628
namespace cpt18_q_task_8 {
    void func() {
        std::string str = "ABCJHDICHFIDIHDIFHIO";

        for (std::string::reverse_iterator iterator = str.rbegin(); iterator != str.rend(); iterator++) {
            std::cout << *iterator << " ";
        }
    }
}

#endif //PLAYGROUND_CPT18_Q_TASK_8_H
