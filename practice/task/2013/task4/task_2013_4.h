//
// Created by schwarzeni on 2019-03-22.
//

#ifndef PRACTICE_TASK_2013_4_H
#define PRACTICE_TASK_2013_4_H

#include <iostream>
#include <iomanip>

namespace task_2013_4 {
    void func() {
        int number = 1;
        int accuracy;
        int factorial = 1;
        int x;
        double e = 1.0;
        double exponent = 1.0;

        std::cout << "Enter exponent: ";
        std::cin >> x;

        std::cout << "Enter desired accuracy of e: ";
        std::cin >> accuracy;

        while (number < accuracy) {
            exponent *= x;
            factorial *= number;
            e += exponent / factorial;
            number++;
        }

        std::cout << "e to the " << x << " is " << std::setprecision(accuracy) << std::fixed <<  e << std::endl;

    }
}

#endif //PRACTICE_TASK_2013_4_H
