//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_26_H
#define PLAYGROUND_CPT21_26_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

namespace book_task_q_cpt21_26 {

    void analysis(char *sentence) {
        const int kArraySize = 26;
        int count[kArraySize] = {0};
        int size = static_cast<int>(std::strlen(sentence));

        for (int i = 0; i < size; i++) {
            if (std::isalpha(sentence[i])) {
                int tmp = std::tolower(sentence[i]) - 'a';
                count[tmp]++;
            }
        }

        for (int i = 0; i < kArraySize; i++) {
            std::cout << std::setw(5) << static_cast<char>(i + 'a') << std::setw(5) << count[i] << std::endl;
        }
    }

    void func() {
//        char sentence[] = "aaa bbb aaa bbb aaa cccc aaa djasoo gmgmdsasmp dasdas dsarc fs fdfd fdsfsa sdmfjvvkjdiowupreot[evnsdmkvKcsklfcksadka";
        char sentence[] = "aaa bbb aaa bbb aaa cccc aaa ";
        analysis(sentence);
    }
}

#endif //PLAYGROUND_CPT21_26_H
