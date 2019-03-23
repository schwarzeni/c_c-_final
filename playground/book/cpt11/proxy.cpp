//
// Created by schwarzeni on 2019-03-11.
//

#include "proxy.h"

namespace cpt11 {
    cpt11::Proxy::Proxy(int value) : obj_(new cpt11::Obj(value)) {}

    void cpt11::Proxy::setValue(int value) {
        this->obj_->setValue(value);
    }

    int cpt11::Proxy::getValue() const {
        return this->obj_->getValue();
    }

    std::ostream &operator<<(std::ostream &os, const Proxy &proxy) {
        os << "obj_: " << proxy.obj_->getValue();
        return os;
    }

    const cpt11::Proxy Proxy::operator++() {
        this->obj_->setValue(this->obj_->getValue() + 1);
        return *this;
    }

    const cpt11::Proxy Proxy::operator++(int) {
        const int data = this->obj_->getValue();
        this->obj_->setValue(this->obj_->getValue() + 1);
        return Proxy(data);
    }



//    std::ostream &operator<<(std::ostream &os, const cpt11::Proxy &proxy) {
//        return os << proxy.obj_->getValue();
//    }
}


