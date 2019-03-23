#include <utility>

//
// Created by schwarzeni on 2019-03-12.
//

#ifndef PLAYGROUND_CPT16_AUTO_PTR_H
#define PLAYGROUND_CPT16_AUTO_PTR_H

#include "string"
#include "iostream"

namespace cpt16_auto_ptr {
    class Person {
        friend std::ostream &operator<<(std::ostream &os, const Person &p) {
            os << p.getName();
            return os;
        }

        friend std::ostream &operator<<(std::ostream &os, const std::unique_ptr<Person> &p) {
            os << p->getName();
            return os;
        }

    public:
        std::string getName() const {
            return this->name;
        }

        void setName(std::string name) {
            this->name = std::move(name);
        }

        explicit Person(std::string name) : name(std::move(name)) {}

    private:
        std::string name;
    };

    void func() {

        std::unique_ptr<cpt16_auto_ptr::Person> ptrPerson(new Person("AAA"));
        ptrPerson->setName("BBB");
        std::cout << ptrPerson << std::endl;
    }
}

#endif //PLAYGROUND_CPT16_AUTO_PTR_H
