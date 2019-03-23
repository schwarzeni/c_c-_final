//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_OBJ1_H
#define PLAYGROUND_OBJ1_H

#include <string>

namespace cpt12_inherit {
    class Base {
    public:
        Base(std::string &name, std::string &code)
                : name(std::move(name)), code(std::move(code)) {
            std::cout << "父类初始化" << std::endl;
        }

        const std::string &getName() const {
            return name;
        }

        virtual void setName(const std::string &name) {
            Base::name = name;
        }

        const std::string &getCode() const {
            return code;
        }

        void setCode(const std::string &code) {
            Base::code = code;
        }

        ~Base() {
            std::cout << "父类销毁" << std::endl;
        }


    private:
        std::string name;
        std::string code;
    };
}

#endif //PLAYGROUND_OBJ1_H
