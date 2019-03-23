//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_BASE2_H
#define PLAYGROUND_BASE2_H

#include <iostream>

namespace cpt12_inherit {
    class Base2 {
    public:
        Base2() {
            std::cout << "Base2 初始化" << std::endl;
        }
        ~Base2() {
            std::cout << "Base2 销毁" << std::endl;
        }
    };
}

#endif //PLAYGROUND_BASE2_H
