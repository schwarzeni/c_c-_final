//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_29_H
#define PLAYGROUND_CPT21_29_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

namespace book_task_q_cpt21_29 {
    void func() {
        char str[] = "bdsaasd ddsdadED bdaasdaED bdasdasdas edasdasED EDdsdsds dsdsED";
        char findStr[] = "ED";

        std::cin.getline(str, std::strlen(str) + 1);
        std::cout << str << std::endl;

        const int kSize = (int) std::strlen(str);

        char *tokenptr = std::strtok(str, " ");
        while (tokenptr != 0) {
            int cur_str_len = (int) std::strlen(tokenptr);
            if (cur_str_len >= 2 && tokenptr[cur_str_len - 1] == 'D' && tokenptr[cur_str_len - 2] == 'E') {
                std::cout << tokenptr << std::endl;
            }
            tokenptr = std::strtok(0, " ");
        }
    }
}

#endif //PLAYGROUND_CPT21_29_H
