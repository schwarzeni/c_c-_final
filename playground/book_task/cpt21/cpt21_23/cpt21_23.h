//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_23_H
#define PLAYGROUND_CPT21_23_H

#include <cstdlib>
#include <iostream>

namespace book_task_q_cpt21_23 {
    void search(char *sentence, char *searchStr) {
        char *ptr = nullptr;
        do {
            ptr = std::strstr(sentence, searchStr);
            if (ptr) {
                std::cout << ptr << std::endl;
                sentence = ptr + 1;
            }
        } while (ptr && sentence);
    }

    void func() {
        char sentence[] = "aaa bbb aaa bbb aaa cccc aaa";
        char searchStr[] = "aaa";
        search(sentence, searchStr);
    }
}

#endif //PLAYGROUND_CPT21_23_H
