//
// Created by schwarzeni on 2019-03-22.
//

#ifndef PRACTICE_TASK_2013_3_H
#define PRACTICE_TASK_2013_3_H

#include <iostream>
#include <iomanip>

namespace task_2013_3 {
    bool isPrimes(int data) {
        if (data == 1) return false;
        if (data == 2 || data == 3) return true;

        int end = data / 2;
        for (int i = 2; i <= end; i++) {
            if (data % i == 0) return false;
        }
        return true;
    }


    void getPrimes() {
        int start = 1;
        int end = 2000;
        int count = 0;
        for (int i = start; i <= end; i++) {
            if (isPrimes(i)) {
                std::cout <<  std::right << std::setw(5) << i << " ";
                count++;
            }
            if (count != 0 && count % 10 == 0) {
                std::cout << std::endl;
                count = 0;
            }
        }
    }

    void func() {
        getPrimes();
    }
}

#endif //PRACTICE_TASK_2013_3_H
