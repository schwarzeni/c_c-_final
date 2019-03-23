//
// Created by schwarzeni on 2019-03-17.
//

#ifndef BOOK_TASK_CPT_6_Q_11_H
#define BOOK_TASK_CPT_6_Q_11_H

#include <iostream>
#include <cmath>

namespace cpt_6_q_11 {
    void func() {
        std::cout << std::fabs(7.5) <<std::endl;
        std::cout << std::floor(7.5) <<std::endl;
        std::cout << std::fabs(0.0) <<std::endl;
        std::cout << std::ceil(0.0) <<std::endl;
        std::cout << std::fabs(-6.4) <<std::endl;
        std::cout << std::ceil(-6.4) <<std::endl;
        std::cout << std::ceil(-std::fabs(-8+std::floor(-5.5))) <<std::endl;
    }
}

#endif //BOOK_TASK_CPT_6_Q_11_H
