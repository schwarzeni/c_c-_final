//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_OBJ_H
#define PLAYGROUND_OBJ_H

#include <ostream>

namespace cpt11 {
    class Obj {
    public:
        explicit Obj(int value) : value_(value) {}

        int getValue() const {
            return this->value_;
        }

        void setValue(int value) {
            this->value_ = value;
        }

        friend std::ostream &operator<<(std::ostream &os, const cpt11::Obj &obj) {
            os << obj.getValue();
            return os;
        }

    private:
        int value_;
    };
}

#endif //PLAYGROUND_OBJ_H
