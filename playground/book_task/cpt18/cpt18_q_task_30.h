//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT18_Q_TASK_30_H
#define PLAYGROUND_CPT18_Q_TASK_30_H

#include <iostream>
#include <sstream>

namespace cpt18_q_task_30 {
    void func() {
        std::string line;

        while (std::getline( std::cin, line )) {
            std::istringstream input(line);
            std::string word;
            while ( input >> word ) {
                std::cout << ( word ) << ' ';
            }
            std::cout << std::endl;
        }
    }
}

#endif //PLAYGROUND_CPT18_Q_TASK_30_H
