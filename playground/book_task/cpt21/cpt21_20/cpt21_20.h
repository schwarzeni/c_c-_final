//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_20_H
#define PLAYGROUND_CPT21_20_H

#include <iostream>
#include <algorithm>

// 大小写转换
namespace book_task_q_cpt21_20 {
    void func() {
        char s[100];
        std::cin.getline(s, 100);
        std::string upperStr(s);
        std::string lowerStr(s);

        std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);

        std::cout << upperStr << std::endl;
        std::cout << lowerStr << std::endl;
    }
}

#endif //PLAYGROUND_CPT21_20_H
