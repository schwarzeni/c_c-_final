//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_HEROTEST_H
#define PLAYGROUND_HEROTEST_H

#include "Hero.h"
#include "Superman.h"
#include "Batman.h"

namespace cpt13_polymorphism {

    void func() {
        Hero *hero1 = new cpt13_polymorphism::Superman("AAAA");
        Hero *hero2 = new cpt13_polymorphism::Batman("bbbb");

        hero1->sayHi();
        hero2->sayHi();
    }
}

#endif //PLAYGROUND_HEROTEST_H
