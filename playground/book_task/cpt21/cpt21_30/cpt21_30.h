//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_30_H
#define PLAYGROUND_CPT21_30_H

#include <iostream>
#include <iomanip>


// 会乱码
namespace book_task_q_cpt21_30 {
    void func() {
        for ( int c = 0; c <= 255; c++ )
        {
            if ( c % 7 == 0 )
                std::cout << '\n';

            std::cout << std::setw( 6 ) << c << std::setw( 3 ) << static_cast< char > ( c );
        } // end for

        std::cout << std::endl;
    }
}
#endif //PLAYGROUND_CPT21_30_H
