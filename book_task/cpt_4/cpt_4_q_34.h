//
// Created by schwarzeni on 2019-03-16.
//

#ifndef BOOK_TASK_CPT_4_Q_34_H
#define BOOK_TASK_CPT_4_Q_34_H

#include <iostream>

namespace cpt_4_q_34 {
    void func() {
        int number = 1; // counter
        int accuracy; // accuracy of estimate
        int factorial = 1; // value of factorial
        double e = 1.0; // estimate value of e

        // get accuracy
        std::cout << "Enter desired accuracy of e: ";
        std::cin >> accuracy;

        // calculate estimation
        while ( number < accuracy )
        {
            factorial *= number;
            e += 1.0 / factorial;
            number++;
        } // end while

        std::cout << "e is " << e << std::endl;
    }
}

#endif //BOOK_TASK_CPT_4_Q_34_H
