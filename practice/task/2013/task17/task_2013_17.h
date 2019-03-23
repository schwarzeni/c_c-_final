//
// Created by schwarzeni on 2019-03-22.
//

#ifndef PRACTICE_TASK_2013_17_H
#define PRACTICE_TASK_2013_17_H

#include <iostream>
namespace task_2013_17 {

    class Array {
    public:
        int operator()(int row, int col) {
            std::cout << row << " " << col << std::endl;
            return 0;
        }
    };

    void func() {
        Array arr;
        arr(2,3);
    }
}

#endif //PRACTICE_TASK_2013_17_H
