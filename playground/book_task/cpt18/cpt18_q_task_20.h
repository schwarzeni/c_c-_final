//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT18_Q_TASK_20_H
#define PLAYGROUND_CPT18_Q_TASK_20_H

#include <iostream>
#include <cstring>
#include <string>

namespace cpt18_q_task_20 {
    void func() {
        std::string sentence = "dasds,dsadsa?dsa;423432.fdfd";

        std::string sign = ",?;.";

        unsigned long idx = sentence.find_first_of(sign);
        while (idx != std::string::npos) {
            sentence.replace(idx, 1, " ");
            idx = sentence.find_first_of(sign);
        }

        char *sentenceArr = new char[sentence.size() + 1];
        std::strcpy(sentenceArr, sentence.c_str());
        char *token = std::strtok(sentenceArr, " ");
        while (token != 0) {
            std::cout << token << std::endl;
            token = std::strtok(nullptr, " ");
        }

        delete[] sentenceArr;
    }
}

#endif //PLAYGROUND_CPT18_Q_TASK_20_H
