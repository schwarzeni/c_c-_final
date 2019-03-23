//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_SUPERMAN_H
#define PLAYGROUND_SUPERMAN_H

#include <iostream>
#include "Hero.h"

namespace cpt13_polymorphism {
    class Superman : public cpt13_polymorphism::Hero {
    public:
        explicit Superman(std::string name) : cpt13_polymorphism::Hero(std::move(name)) {}

        void sayHi() const override{
            std::cout << "I'm Superman " << this->getName() << std::endl;
        }
    };
}

#endif //PLAYGROUND_SUPERMAN_H
