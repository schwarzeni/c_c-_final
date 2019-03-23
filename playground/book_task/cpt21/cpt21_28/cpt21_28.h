//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_28_H
#define PLAYGROUND_CPT21_28_H

#include <iostream>
#include <cstdlib>

namespace book_task_q_cpt21_28 {
    void func() {
        char str[] = "bdsaasd ddsdadas bdaasda bdasdasdas edasdas";
        char *tokenPtr;
        std::cin.getline(str, 1000);

        tokenPtr = std::strtok(str, " ");
        while (tokenPtr != 0) {
            if (std::strchr(tokenPtr, 'b') == tokenPtr) {
                std::cout << tokenPtr << std::endl;
            }
            tokenPtr = std::strtok(0, " ");
        }
    }
}

#endif //PLAYGROUND_CPT21_28_H
