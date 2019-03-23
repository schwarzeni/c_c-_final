//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_40_H
#define PLAYGROUND_CPT21_40_H

#include <iostream>
#include <cstdlib>
#include <cstring>

namespace book_task_q_cpt21_40 {
    void func() {
        char sentence[] = "abc defgh ijklm nopqr stu";
        char *tokenPtr = std::strtok(sentence, " ");
        while (tokenPtr != nullptr) {
            int size = (int) std::strlen(tokenPtr);
            char tmpChar[size + 2];
            std::strcpy(tmpChar, tokenPtr + 2);
            std::strncat(tmpChar, tokenPtr, 2);
            std::strcat(tmpChar, "ay");

            std::cout << tmpChar << std::endl;

            tokenPtr = std::strtok(0, " ");
        }
    }
}

#endif //PLAYGROUND_CPT21_40_H
