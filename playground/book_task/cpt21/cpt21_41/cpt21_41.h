//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_41_H
#define PLAYGROUND_CPT21_41_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

namespace book_task_q_cpt21_41 {
    void func() {
        char raw_tel[] = "(123)456-7890";
        char *area;
        char tel[8];

        area = strtok( raw_tel, "()" );
        char *tokenPtr = strtok( 0, "-" );
        std::strcpy( tel, tokenPtr );
        tokenPtr = strtok(0, "");
        std::strcat(tel, tokenPtr);

        std::cout << area  << " " << std::right << std::setw(10) << tel << std::endl;
    }
}

#endif //PLAYGROUND_CPT21_41_H
