//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT18_Q_TASK_12_H
#define PLAYGROUND_CPT18_Q_TASK_12_H

#include <iostream>

// 反向打印字符串，大小写转换
namespace cpt18_q_task_12 {
    void func() {
        std::string str = "abcdEGFhiJKLmNoPQ";

        for (std::string::reverse_iterator it = str.rbegin(); it != str.rend(); it++) {
            if (std::isupper(*it)) {
                std::cout << static_cast<char> (std::tolower(*it));
            } else {
                std::cout << static_cast<char> (std::toupper(*it));
            }
        }
        std::cout << std::endl;

    }
}

#endif //PLAYGROUND_CPT18_Q_TASK_12_H
