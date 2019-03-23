//
// Created by schwarzeni on 2019-03-22.
//

#ifndef PRACTICE_TASK_2013_TASK3_2_H
#define PRACTICE_TASK_2013_TASK3_2_H

#include <cstring>
#include <iostream>

// 切割字符串
namespace task_2013_task3_2 {
    void func() {
        char str[] = "(010)(15012345678)|123|(430070)";
        char *result1 = std::strtok(str, "()");
        char *result2 = std::strtok(nullptr, "()");
        char *result3 = std::strtok(nullptr, "|");
        char *result4 = std::strtok(nullptr, "()");

        std::cout << result1 << " . " << result2 << " . " << result3 << " . " << result4 << std::endl;

    }
}

#endif //PRACTICE_TASK_2013_TASK3_2_H
