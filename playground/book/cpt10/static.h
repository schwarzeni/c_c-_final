//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_STATIC_H
#define PLAYGROUND_STATIC_H

#include <ostream>

namespace cpt10_static {
    class Person {
    public:
        Person() {
            cpt10_static::Person::count++;
        }

        static void init() {
            if (cpt10_static::Person::count <= 0) {
                cpt10_static::Person::count = 0;
            }
        }

        friend std::ostream &operator<<(std::ostream &os, const cpt10_static::Person & p) {
            os <<  "count: " << cpt10_static::Person::count;
            return os;
        }

    private:
        static int count;
    };

    int cpt10_static::Person::count = 0;
}


#endif //PLAYGROUND_STATIC_H
