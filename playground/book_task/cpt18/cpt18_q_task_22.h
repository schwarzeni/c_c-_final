//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT18_Q_TASK_22_H
#define PLAYGROUND_CPT18_Q_TASK_22_H

#include <iostream>

namespace cpt18_q_task_22 {

    void Print(const std::string::reverse_iterator &rend,
               const std::string::reverse_iterator &curr) {
        if (curr == rend) {
            return;
        }

        std::cout << *curr;
        Print(rend, curr+1);
    }

    void func() {
        std::string s;
        std::cout << "Enter a string: ";
        std::getline( std::cin, s, '\n' );

        Print(s.rend(), s.rbegin());
    }
}

#endif //PLAYGROUND_CPT18_Q_TASK_22_H
