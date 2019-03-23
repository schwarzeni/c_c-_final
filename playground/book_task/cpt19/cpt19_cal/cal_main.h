//
// Created by schwarzeni on 2019-03-14.
//

#ifndef PLAYGROUND_CAL_MAIN_H
#define PLAYGROUND_CAL_MAIN_H

#include <iostream>
#include "cal_parser.h"
#include "cal_caler.h"

namespace cpt19_cal {
    void func() {
        char *tokenPtr;
        char sentence[80] = "22233 323232  3232 43";
        tokenPtr = std::strtok(sentence, " ");
        while (tokenPtr != 0) {
            auto *newString = new std::string(tokenPtr);
            std::cout << *newString << std::endl;
            tokenPtr = strtok(0, " ");
        }


        std::string str = "(6 + 2) * 5 - 8 / 4";
        std::string result = cpt19_cal::parse(str);
        std::cout << result << std::endl;
        int value = cpt19_cal::cal(result);
        std::cout << value << std::endl;
    }
}

#endif //PLAYGROUND_CAL_MAIN_H
