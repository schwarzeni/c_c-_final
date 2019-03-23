//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_OBJ2_H
#define PLAYGROUND_OBJ2_H

#include <ostream>
#include "base.h"
#include "base2.h"

namespace cpt12_inherit {
    // 顺序：根据继承顺序执行
    /**
     *  Base2 初始化
        父类初始化
        子类初始化
        bbb 001
        子类销毁
        父类销毁
        Base2 销毁
     */
    class Child : public cpt12_inherit::Base2, public cpt12_inherit::Base {
    public:
        Child(std::string name, std::string code): Base2(), Base(name, code) {
            std::cout << "子类初始化" << std::endl;
        }

        void setName(const std::string &name) override {
            Base::setName(name);
        }

        friend std::ostream &operator<<(std::ostream &os, const Child &child) {
            os << child.getName() << " " << child.getCode();
            return os;
        }

        ~Child() {
            std::cout << "子类销毁" << std::endl;
        }
    };
}

#endif //PLAYGROUND_OBJ2_H
