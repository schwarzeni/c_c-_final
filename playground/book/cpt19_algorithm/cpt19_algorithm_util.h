//
// Created by schwarzeni on 2019-03-14.
//

#ifndef PLAYGROUND_CPT19_ALGORITHM_UTIL_H
#define PLAYGROUND_CPT19_ALGORITHM_UTIL_H

#include <vector>
#include <ctime>

namespace cpt19_algorithm_util {
    std::vector<int> getData(int size) {
        std::srand((unsigned int) std::time(nullptr));

        std::vector<int> array;

        for (int i = 0; i < size; i++) {
            array.push_back(10 + std::rand() % 1000000000);
        }

        return array;
    }

    int *getDataArr(int size) {
        int *arr = new int[size];
        std::vector<int> arrVector = cpt19_algorithm_util::getData(size);
        std::copy(arrVector.cbegin(), arrVector.cend(), arr);
        return arr;
    }

    bool isSorted(std::vector<int> &arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] > arr[i]) {
                return false;
            }
        }
        return true;
    }

    bool isSorted(const int *arr, int size) {
        for (int i = 1; i < size; i++) {
            if (arr[i - 1] > arr[i]) {
                return false;
            }
        }
        return true;
    }
}

#endif //PLAYGROUND_CPT19_ALGORITHM_UTIL_H
