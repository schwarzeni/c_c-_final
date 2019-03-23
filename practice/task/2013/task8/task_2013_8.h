//
// Created by schwarzeni on 2019-03-22.
//

#ifndef PRACTICE_TASK_2013_8_H
#define PRACTICE_TASK_2013_8_H

#include <cstring>
#include <iostream>

namespace task_2013_8 {
    void func() {
        char str[] = "(025)87234865-987";
        // 区号
        char *const result1 = std::strtok(str, "()");

        // 电话
        char *const result2 = std::strtok(nullptr, "-");

        // 分机号
        char *const result3 = std::strtok(nullptr, " ");

        std::cout << result1 << " " << result2 << " " << result3 << std::endl;

    }
}

#endif //PRACTICE_TASK_2013_8_H
