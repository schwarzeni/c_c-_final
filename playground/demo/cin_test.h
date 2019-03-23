//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CIN_TEST_H
#define PLAYGROUND_CIN_TEST_H

#include <iostream>

namespace demo_cin_test {
    class CinTest {
        friend std::istream &operator>>(std::istream &is, demo_cin_test::CinTest &cintest) {
            int inputage;
            int input2;


            if (is.peek() == '#') {
                is.ignore();
                std::cout << "end" << std::endl;
//                is.clear(std::ios::failbit);
            } else {
                is >> inputage >> input2;
                cintest.age = inputage;
            }
            return is;
        }
    public:
        int age;
    };

    void func() {
        CinTest cinTest{};
        std::cin >> cinTest;
        int input = 0;
        std::cin >> input;
        std::cout << "Input is " << input << std::endl;
    }
}

#endif //PLAYGROUND_CIN_TEST_H
