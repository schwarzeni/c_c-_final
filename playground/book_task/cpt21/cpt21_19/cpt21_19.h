//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_19_H
#define PLAYGROUND_CPT21_19_H

#include <iostream>
#include <iomanip>

// 不可以被2开方
namespace book_task_q_cpt21_19 {
    bool mystery( unsigned bits )
    {
        const int SHIFT = 8 * sizeof( unsigned ) - 1;
        const unsigned MASK = 1 << SHIFT;
        unsigned total = 0;

        for ( int i = 0; i < SHIFT + 1; i++, bits <<= 1 )

            if ( ( bits & MASK ) == MASK )
                ++total;

        return !( total % 2 );
    }

    void func() {
        std::cout << std::boolalpha << mystery(64) << std::endl;
    }
}

#endif //PLAYGROUND_CPT21_19_H
