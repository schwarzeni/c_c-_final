//
// Created by schwarzeni on 2019-03-10.
//

#ifndef PLAYGROUND_STATIC_H
#define PLAYGROUND_STATIC_H

#include <iostream>
namespace cpt7_static {

    class C {
    public:
        static const int kNum = 3;
    };

    void func() {
        const int arrSize = 3;
        static int arr[arrSize] = {};
        for (int i = 0; i < arrSize; i++) {
            arr[i] += 5;
        }

        for (int i = 0 ;i < C::kNum; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}

#endif //PLAYGROUND_STATIC_H
