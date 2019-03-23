#include <iostream>

//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_BATMAN_H
#define PLAYGROUND_BATMAN_H

#include "Hero.h"

namespace cpt13_polymorphism {
    class Batman : public cpt13_polymorphism::Hero {
    public:
        explicit Batman(std::string name) : cpt13_polymorphism::Hero(std::move(name)) {}

        void sayHi() const override;
    };
}

#endif //PLAYGROUND_BATMAN_H
