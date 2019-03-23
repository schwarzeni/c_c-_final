//
// Created by schwarzeni on 2019-03-12.
//

#ifndef PLAYGROUND_CPT15_Q_TASK_18_H
#define PLAYGROUND_CPT15_Q_TASK_18_H

#include "iostream"

namespace cpt15_q_task_18 {
    void func() {
        int SIZE = 80;
        char array[SIZE]; // array to hold getline() input
        char array2[SIZE]; // array to hold get() input
        char c;// holds next input value

        // prompt user to enter string and use getline() to store it
        std::cout << "Enter a sentence to test getline() and get():\n";
        std::cin.getline(array, SIZE, '*');
        std::cout << array << '\n';

        std::cin >> c; // read next character in input
        std::cout << "The next character in the input is: " << c << '\n';

        // use get() to obtain next value held in array
        std::cin.get(array2, SIZE, '*');
        std::cout << array2 << '\n';

        std::cin >> c; // read next character in input
        std::cout << "The next character in the input is: " << c << '\n';
    }
}

#endif //PLAYGROUND_CPT15_Q_TASK_18_H
