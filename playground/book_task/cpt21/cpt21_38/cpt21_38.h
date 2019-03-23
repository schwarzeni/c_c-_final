//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_38_H
#define PLAYGROUND_CPT21_38_H

#include <iostream>
#include <ctime>
#include <cstdlib>

const int SIZE = 100;

namespace book_task_q_cpt21_38 {
    const int SIZE = 100;

    void func() {
        const char *article[] = {"the", "a", "one", "some", "any"};
        const char *noun[] = {"boy", "girl", "dog", "town", "car"};
        const char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
        const char *preposition[] = {"to", "from", "over", "under", "on"};
        char sentence[SIZE] = "";

        std::srand(std::time(0));

        for (int i = 1; i <= 20; ++i) {
            // uses function strcat to concatenate random sentences
            std::strcat(sentence, article[std::rand() % 5]);
            std::strcat(sentence, " ");
            std::strcat(sentence, noun[std::rand() % 5]);
            std::strcat(sentence, " ");
            std::strcat(sentence, verb[std::rand() % 5]);
            std::strcat(sentence, " ");
            std::strcat(sentence, preposition[std::rand() % 5]);
            std::strcat(sentence, " ");
            std::strcat(sentence, article[std::rand() % 5]);
            std::strcat(sentence, " ");
            std::strcat(sentence, noun[std::rand() % 5]);

            // print the current sentence
            std::cout << static_cast< char > ( std::toupper(sentence[0]))
                 << &sentence[1] << ".\n";

            sentence[0] = '\0'; // reset the sentence
        } // end for

        std::cout << std::endl;
    }
}

#endif //PLAYGROUND_CPT21_38_H
