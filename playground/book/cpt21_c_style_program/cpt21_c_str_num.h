//
// Created by schwarzeni on 2019-03-14.
//

#ifndef PLAYGROUND_CPT21_C_STR_NUM_H
#define PLAYGROUND_CPT21_C_STR_NUM_H

#include <iostream>
#include <cstdlib>
#include <cstring>

namespace cpt21_c_str_num {
    void func() {
        long x;
        const char *str1 = "123456789abc";
        char *remainPtr;

        x = std::strtol(str1, &remainPtr, 0);

        std::cout << x << std::endl;

        std::cout << "=========================" << std::endl;

        char xc[] = "abcdefghijk";
        char xct[1];
        char *result = std::strcpy(xct, xc);
        std::cout << xct << std::endl;
        std::cout << result << std::endl;

        std::cout << "=========================" << std::endl;
        char xcc[] = "aaa bbb ccc ddd eee fff ggg hhh kkk";
        char xcc_r[4];
        std::memcpy(xcc_r, xcc, 10);
        std::cout << "std::memcpy " << xcc_r << std::endl;

        std::cout << "=========================" << std::endl;

        char xcm[] = "aaa bbb ccc ddd eee fff ggg hhh kkk";
        std::memmove(xcm, &xcm[7], 10);
        std::cout << "std::memmove " << xcm << std::endl;
    }
}

#endif //PLAYGROUND_CPT21_C_STR_NUM_H
