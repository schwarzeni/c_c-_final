//
// Created by schwarzeni on 2019-03-11.
//

#include "Batman.h"

namespace cpt13_polymorphism {

    void Batman::sayHi() const {
        std::cout << "I'm Batman " << this->getName() << std::endl;
    }
}