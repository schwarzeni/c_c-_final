//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_PERSON_H
#define PLAYGROUND_PERSON_H

#include <string>


namespace cpt13_polymorphism {
    class Hero {
    public:
        explicit Hero(std::string name) : name(std::move(name)) {}

        virtual void sayHi() const = 0;

        const std::string &getName() const {
            return name;
        }

    private:
        std::string name;
    };

}

#endif //PLAYGROUND_PERSON_H
