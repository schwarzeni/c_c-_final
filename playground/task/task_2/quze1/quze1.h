//
// Created by 倪震洋 on 2019-03-07.
//

#ifndef PLAYGROUND_QUZE1_H
#define PLAYGROUND_QUZE1_H

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

namespace shiyanlou_lou12{
    std::vector<std::string> split_string(const std::string &data, char c) {
        std::vector<std::string> ret;
        auto old = std::cbegin(data);
        for(auto it = old; it != std::cend(data); ++it) {
            if( *it == c ) {
                ret.emplace_back( old, ++it );
                old = it;
            }
        }
        if( old != cend(data) ) {
            ret.emplace_back( old, cend(data) );
        }
        return ret;
    }

    void func() {
        std::string str("Welcome to shiyanlou contest lou12");

        std::vector<std::string> v = split_string(str, ' ');
        for(const std::string &s : v) {
            std::cout << s << std::endl;
        }
    }
}


#endif //PLAYGROUND_QUZE1_H
