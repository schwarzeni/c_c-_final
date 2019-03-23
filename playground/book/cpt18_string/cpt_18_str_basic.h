//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT_18_STR_BASIC_H
#define PLAYGROUND_CPT_18_STR_BASIC_H

#include <iostream>
#include <sstream>

namespace cpt_18_str_basic {
    void func() {
        std::string str("323232323232dsdsdsdsds");
        std::cout << str.size() << std::endl;
        std::cout << str.max_size() << std::endl;
        std::cout << str.capacity() << std::endl;

        std::cout << "============" << std::endl;
        std::ostringstream sss;

        sss << "1" << "2" << "3" << "4";

        std::cout << sss.str();

        std::cout << "============" << std::endl;

        std::string of = "232";
        std::cout << of[5] << std::endl;

        std::cout << "============" << std::endl;

        std::string strstr = "hello";
        std::cout << strstr.data() << std::endl;
        std::cout << strstr.c_str() << std::endl;

        std::cout << "============" << std::endl;
        std::string strstrstr = "xenon";
        strstrstr.erase(strstrstr.rfind('x'), 1);
        std::cout << strstrstr << std::endl;

    }
}

#endif //PLAYGROUND_CPT_18_STR_BASIC_H
