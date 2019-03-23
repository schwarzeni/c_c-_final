//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT22_STL_ALGORITHM_H
#define PLAYGROUND_CPT22_STL_ALGORITHM_H

#include <iostream>
#include <algorithm>
#include <vector>

namespace cpt22_stl_algorithm {
    // 填充算法
    void fill_genreate() {
        std::ostream_iterator<char> output(std::cout, " ");
        std::vector<char> chars(10);

        // 全部填充
        std::fill(chars.begin(), chars.end(), '5');

        // 5 5 5 5 5 5 5 5 5 5
        std::copy(chars.begin(), chars.end(), output);
        std::cout << std::endl;

        // 部分填充
        std::fill_n(chars.begin(), 5, 'A');

        // A A A A A 5 5 5 5 5
        std::copy(chars.begin(), chars.end(), output);
        std::cout << std::endl;

        // 使用函数填充
        std::generate(chars.begin(), chars.end(), [] {
            static char letter = 'A';
            return letter++;
        });

        // A B C D E F G H I J
        std::copy(chars.begin(), chars.end(), output);
        std::cout << std::endl;
    }


    void func() {
        fill_genreate();
    }
}

#endif //PLAYGROUND_CPT22_STL_ALGORITHM_H
