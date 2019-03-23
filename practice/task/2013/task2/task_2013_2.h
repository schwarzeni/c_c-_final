//
// Created by schwarzeni on 2019-03-22.
//

#ifndef PRACTICE_TASK_2013_2_H
#define PRACTICE_TASK_2013_2_H

#include <iostream>

namespace task_2013_2 {
    // 求和
    int sum(int *data, int size) {
        int result = 0;
        for (int i = 0; i < size; i++) {
            result += *(data + i);
        }
        return result;
    }


    void func() {
        int size;
        std::cout << "请输入个数:" << std::endl;
        std::cin >> size;
        int data[size];

        std::cout << "请输入" << size << "个数字:" << std::endl;
        for (int i = 0 ; i < size; i++) {
            std::cin >> data[i];
        }

        int result = sum(data, size);

        std::cout << "求和结果如下:" << std::endl;
        std::cout << result << std::endl;
    }
}

#endif //PRACTICE_TASK_2013_2_H
