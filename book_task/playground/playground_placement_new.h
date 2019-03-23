//
// Created by schwarzeni on 2019-03-21.
//

#ifndef BOOK_TASK_PLAYGROUND_PLACEMENT_NEW_H
#define BOOK_TASK_PLAYGROUND_PLACEMENT_NEW_H

#include <new>
#include <iostream>

namespace playground_placement_new {
    class A {
    public:
        A() {
            std::cout << "A 构造函数" << std::endl;
        }

        void sayHello() {
            std::cout << "say hello" << std::endl;
        }

        ~A() {
            std::cout << "A 析构函数" << std::endl;
        }
    };

    void func() {
        char s[sizeof(A)];
        A* p = (A*)s;
        new(p) A();
        p->sayHello();
    }
}

#endif //BOOK_TASK_PLAYGROUND_PLACEMENT_NEW_H
