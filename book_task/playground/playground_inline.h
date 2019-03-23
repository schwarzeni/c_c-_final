//
// Created by schwarzeni on 2019-03-23.
//

#ifndef BOOK_TASK_PLAYGROUND_INLINE_H
#define BOOK_TASK_PLAYGROUND_INLINE_H

#include <iostream>

namespace playground_inline {
    class T {
    public:
        void display();
    };

    inline void playground_inline::T::display() {
        std::cout << "显示" << std::endl;
    }
}

#endif //BOOK_TASK_PLAYGROUND_INLINE_H
