//
// Created by schwarzeni on 2019-03-22.
//

#ifndef PRACTICE_TASK_2013_11_H
#define PRACTICE_TASK_2013_11_H

#include <iostream>
namespace task_2013_11 {
    template<typename T>
    int recursion(T arr[], int size, int minIdx, int currIdx) {
        if (currIdx == size) return minIdx;

        if (arr[currIdx] < arr[minIdx]) {
            minIdx = currIdx;
        }
        return recursion(arr, size, minIdx, ++currIdx);
    }

    void func() {
        int arr[] = {5, 4, 3, 2, 7, 8, 6, 3, 7, 8, 6, 3, 2, 57, 3, 0, 6};
        int result = recursion<int>(arr, 17, 0, 0);
        std::cout << arr[result] << std::endl;
    }
}

#endif //PRACTICE_TASK_2013_11_H
