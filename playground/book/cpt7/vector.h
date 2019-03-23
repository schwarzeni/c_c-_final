//
// Created by schwarzeni on 2019-03-10.
//

#ifndef PLAYGROUND_VECTOR_H
#define PLAYGROUND_VECTOR_H

namespace cpt7_vector {

#include <iostream>
#include <vector>
#include <algorithm>


    void printVector(const std::vector<int> v) {
//            for (const int &i : v) {
//                    std::cout << i << " ";
//            }
        auto it = v.begin();
        for (; it != v.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    void func() {
        std::vector<int> v1;

        v1.push_back(23);
        v1.push_back(32);
        v1.push_back(54);

        std::vector<int> v2(v1);

        v2.push_back(2233);

        cpt7_vector::printVector(v1);
        cpt7_vector::printVector(v2);
    }

}

#endif //PLAYGROUND_VECTOR_H
