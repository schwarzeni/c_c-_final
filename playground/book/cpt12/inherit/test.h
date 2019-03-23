//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_TEST_H
#define PLAYGROUND_TEST_H

#include <iostream>
#include "child.h"

namespace cpt12_inherit {
    void func() {
        cpt12_inherit::Child* child = new cpt12_inherit::Child("aaa", "001");
        child->setName("bbb");
        std::cout << *child << std::endl;

        delete child;
    }
}

#endif //PLAYGROUND_TEST_H
