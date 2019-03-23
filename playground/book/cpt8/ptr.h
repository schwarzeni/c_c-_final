//
// Created by schwarzeni on 2019-03-10.
//

#ifndef PLAYGROUND_PTR_H
#define PLAYGROUND_PTR_H

namespace cpt8_ptr {

#include <iostream>


    void ptrFunc(void (*cb)(int)) {
        (*cb)(2233);
    }

    void callback(int data) {
        std::cout << data << std::endl;
    }

    // 测试大小
    void func() {
        char color[] = "blue";
        std::cout << sizeof(color) << std::endl;

        char sentence[10];
//        std::cin.getline(sentence, 10, '\n');

        cpt8_ptr::ptrFunc(cpt8_ptr::callback);
    }

}

#endif //PLAYGROUND_PTR_H
