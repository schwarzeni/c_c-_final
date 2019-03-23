//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_PROXY_H
#define PLAYGROUND_PROXY_H


#include <iostream>
#include "obj.h"

namespace cpt11 {
    class Proxy {
    public:
        explicit Proxy(int);

        int getValue() const;

        void setValue(int);

//        friend std::ostream&operator<<(std::ostream&, const cpt11::Proxy&);

        friend std::ostream &operator<<(std::ostream &os, const Proxy &proxy);
//
//        friend std::ostream &operator<<(std::ostream & os, const cpt11::Proxy &proxy) {
//            return  os << proxy.obj_;
//        }
        const cpt11::Proxy operator++(int);
        const cpt11::Proxy operator++();

    private:
        cpt11::Obj *obj_;
    };
}

#endif //PLAYGROUND_PROXY_H
