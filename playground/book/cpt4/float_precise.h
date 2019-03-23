//
// Created by 倪震洋 on 2019-03-09.
//

#ifndef PLAYGROUND_FLOAT_PRECISE_H
#define PLAYGROUND_FLOAT_PRECISE_H

#include <iostream>
#include <iomanip>

namespace cpt4_float_precise {
    void func() {
        std::cout << 1.2456 << std::endl;
        std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3) << 1.2456 << std::endl;
        std::cout << std::setprecision(3) << 1.2456 << std::endl;
    }
}

#endif //PLAYGROUND_FLOAT_PRECISE_H
