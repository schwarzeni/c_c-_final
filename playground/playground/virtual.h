#include <utility>

#include <utility>

//
// Created by 倪震洋 on 2019-03-07.
//

#ifndef PLAYGROUND_VIRTUAL_H
#define PLAYGROUND_VIRTUAL_H

#include <iostream>
#include <string>

class Person {
public:
    explicit Person(std::string name): name(std::move(name)) {}
    virtual void sayHi() {}

protected:
    std::string name;
};

class Hero : public Person {
public:
    explicit Hero(std::string name): Person(std::move(name)) {}

    void sayHi() override {
        std::cout << this->name << std::endl;
    }
};


void func_virtual() {
    Person *person = new Hero("hero");
    person->sayHi();
}

#endif //PLAYGROUND_VIRTUAL_H
