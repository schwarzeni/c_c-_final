//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_42_H
#define PLAYGROUND_CPT21_42_H

#include <iostream>
#include <cstdlib>
#include <cstring>

namespace book_task_q_cpt21_42 {
    void func() {
        char str[] = "bdsaasd ddsdadED bdaasdaED bdasdasdas edasdasED EDdsdsds dsdsED";
        char *tokenPtr = std::strtok(str, " ");

        while (tokenPtr != 0) {
            std::cout << tokenPtr << std::endl;
            tokenPtr = std::strtok(0, " ");
        }
    }
}

#endif //PLAYGROUND_CPT21_42_H
