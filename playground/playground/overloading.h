#include <utility>

//
// Created by 倪震洋 on 2019-03-09.
//

#ifndef PLAYGROUND_OVERLOADING_H
#define PLAYGROUND_OVERLOADING_H

#include <iostream>
#include <string>

namespace overloading {

    class P {
    public:
        std::string name;
        char c;

        P(std::string name, char c) : name(std::move(name)), c(c) {}

        friend std::ostream &operator<<(std::ostream &os, const P &p) {
            os << "name: " << p.name << " char to in " << static_cast<int>(p.c);
            return os;
        }

    };
}


#endif //PLAYGROUND_OVERLOADING_H
