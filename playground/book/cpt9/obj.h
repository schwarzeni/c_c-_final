//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_OBJ_H
#define PLAYGROUND_OBJ_H

namespace ctp9_obj {

#include <iostream>

    class C {
    public:
        void setValue(int value) {
            this->value = value;
        }

        void print() {
            std::cout << this->value << std::endl;
        }

    private:
        int value;
    };

    void func() {
        ctp9_obj::C c;
        ctp9_obj::C *cptr = &c;
        ctp9_obj::C &cref = c;

        c.setValue(23);
        c.print();

        cptr->print();
        cref.print();

        cptr->setValue(32);
        c.print();
        cref.print();

        cref.setValue(2233);
        c.print();
        cptr->print();
    }
}

#endif //PLAYGROUND_OBJ_H
