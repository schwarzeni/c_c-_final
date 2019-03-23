//
// Created by schwarzeni on 2019-03-12.
//

#ifndef PLAYGROUND_CPT15_Q_TASK_17_H
#define PLAYGROUND_CPT15_Q_TASK_17_H

#include "iostream"
#include "iomanip"

namespace cpt15_q_task_17 {
    void func() {
        std::cout << std::setw(7) << "Decimal"
                  << std::setw(9) << "Octal"
                  << std::setw(15) << "Hexadecimal"
                  << std::setw(13) << "Character"
                  << std::showbase << "\n";

        for (int loop = 33; loop <= 126; loop++) {
            std::cout << std::setw(7) << std::dec << loop
                      << std::setw(9) << std::oct << loop
                      << std::setw(15) << std::hex << loop
                      << std::setw(13) << static_cast< char > (loop) << std::endl;
        }

    }
}

#endif //PLAYGROUND_CPT15_Q_TASK_17_H
