//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT18_Q_TASK_7_H
#define PLAYGROUND_CPT18_Q_TASK_7_H

#include <iostream>
#include <string>

// +13字符串加密 628
namespace cpt18_q_task_7 {

    int code = 13;

    void Encrypt(std::string &str) {
        for (char &i : str) {
            char c = i;
            c - 'a' <= 12 ? c += 13 : c -= 13;
            i = c;
        }
    }

    void Decrypt(std::string &str) {
        for (char &i : str) {
            char c = i;
            c - 'a' <= 12 ? c += 13 : c -= 13;
            i = c;
        }
    }

    void func() {
        std::string str = "abcdezkyy";
        Encrypt(str);
        std::cout << str.c_str() << std::endl;
        Decrypt(str);
        std::cout << str.c_str() << std::endl;
    }
}


#endif //PLAYGROUND_CPT18_Q_TASK_7_H
