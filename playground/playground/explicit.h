#include <utility>

//
// Created by 倪震洋 on 2019-03-07.
//

#ifndef PLAYGROUND_EXPLICIT_H
#define PLAYGROUND_EXPLICIT_H

#include <iostream>
#include <string.h>


class E {
public:
    std::string name;
    int CompareTo(const E & other) {
        return std::strcmp(this->name.c_str(), other.name.c_str());
    }
    // explicit
    E(std::string name="") : name(std::move(name)) {}
};

void func_explicit() {
    E *e1 = new E("nzy");
    std::string other = "lj";
    std::cout << e1->CompareTo(other) << std::endl;
}

#endif //PLAYGROUND_EXPLICIT_H
