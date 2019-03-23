//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_FRIEND_H
#define PLAYGROUND_FRIEND_H

#include <ostream>
#include <iostream>

namespace cpt10_friend {
    class C {
        friend void setData(cpt10_friend::C&, int);
    public:
        C(int data): data(data) {}

        friend std::ostream &operator<<(std::ostream &os, const C &c) {
            os << "data: " << c.data;
            return os;
        }

        void print() {}
    private:
        int data;
    };

    void setData(cpt10_friend::C & c, int data) {
        c.data = data;
    }

    void func() {
        cpt10_friend::C c(10);
        cpt10_friend::setData(c, 23);
        std::cout << c << std::endl;

        cpt10_friend::C *cc = new cpt10_friend::C(40);
        (*cc).print();
    }
}

#endif //PLAYGROUND_FRIEND_H
