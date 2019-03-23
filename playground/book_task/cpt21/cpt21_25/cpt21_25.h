//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_25_H
#define PLAYGROUND_CPT21_25_H

#include <iostream>
#include <cstdlib>

namespace book_task_q_cpt21_25 {
    void searchChr(char *sentence, char chr) {
        char *ptr = nullptr;
        int count = 0;

        do {
            ptr = std::strchr(sentence, chr);
            if (ptr) {
                count++;
                sentence = ptr + 1;
            }
        } while (ptr && sentence);

        std::cout << count << std::endl;
    }

    void func() {
        char sentence[] = "aaa bbb aaa bbb aaa cccc aaa";
        char chr = 'a';
        searchChr(sentence, chr);
    }
}

#endif //PLAYGROUND_CPT21_25_H
