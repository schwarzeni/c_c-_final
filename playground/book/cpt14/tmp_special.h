//
// Created by schwarzeni on 2019-03-12.
//

#ifndef PLAYGROUND_TMP_SPECIAL_H
#define PLAYGROUND_TMP_SPECIAL_H

#include <iostream>
#include <typeinfo>
#include <string>

namespace cpt14_tmp_special {
    template <typename T>
    void func(T) {
        std::cout << " template <typename T>  " << typeid(T).name() << std::endl;
    }

    template<>
    void func(int){
        std::cout << "  template<>  " << typeid(int).name()<<std::endl;
    }

    void func(int){
        std::cout<<"type is int."<<std::endl;
    }

    void FuncTest() {
        int ival=123;
        double dval = 12.32;
        func(ival);
        func<int>(ival);
        func(dval);
    }
}

#endif //PLAYGROUND_TMP_SPECIAL_H
