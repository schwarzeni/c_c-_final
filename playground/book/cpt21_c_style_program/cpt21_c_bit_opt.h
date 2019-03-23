//
// Created by schwarzeni on 2019-03-14.
//

#ifndef PLAYGROUND_CPT21_C_BIT_OPT_H
#define PLAYGROUND_CPT21_C_BIT_OPT_H

#include <iostream>

namespace cpt21_c_bit_opt {

    void myDisplayBits(unsigned value) {
        std::string bitArr;
        int size = 8 * sizeof(unsigned);

        for (unsigned i = 1; i <= size; i++) {
            bitArr.insert(0, value & 1 ? "1" : "0");

            value >>=1;

            if ( i % 8 == 0 && i != size) {
                bitArr.insert(0, 1, ' ');
            }
        }
        std::cout << bitArr << std::endl;
    }

    void displayBits(unsigned value) {
        const int SHIFT = 8 * sizeof(unsigned) - 1;
        const unsigned MASK = 1 << SHIFT;

        for (unsigned i = 1; i <= SHIFT + 1; i++) {
            std::cout << (value & MASK ? '1' : '0');
            value <<= 1;

            if (i % 8 == 0) {
                std::cout << ' ';
            }
        }

        std::cout << std::endl;
    }

    void func() {
        displayBits(65000);
        myDisplayBits(65000);
        displayBits(29);
        myDisplayBits(29);
    }
}

#endif //PLAYGROUND_CPT21_C_BIT_OPT_H
