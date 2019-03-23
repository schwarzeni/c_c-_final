//
// Created by schwarzeni on 2019-03-22.
//

#ifndef PRACTICE_TASK_2013_5_H
#define PRACTICE_TASK_2013_5_H

#include <iostream>
#include <iomanip>
#include <cfloat>

namespace task_2013_5 {
    void func() {
        double result = 0.0;
        double precious = 100000000;
        for (long i = 0; i < precious; i++) {
            double flag = i % 2 == 0 ? 1.0 : -1.0;
            result += flag * 4.0 / (i * 2 + 1);
        }
        std::numeric_limits<double> info;

        std::cout << std::setprecision(52) << result << std::endl;

    }
}

#endif //PRACTICE_TASK_2013_5_H
