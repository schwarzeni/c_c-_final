//
// Created by schwarzeni on 2019-03-14.
//

#ifndef PLAYGROUND_CPT21_C_STRUCTURE_H
#define PLAYGROUND_CPT21_C_STRUCTURE_H

#include <iostream>

namespace cpt21_c_structure {
    struct MyStruct {
        unsigned a : 4;
        unsigned b : 1;
    };

    void func() {
        struct MyStruct myStruct{1000, 1000000};
        std::cout << myStruct.a << " " << myStruct.b << std::endl;
    }
}

#endif //PLAYGROUND_CPT21_C_STRUCTURE_H
