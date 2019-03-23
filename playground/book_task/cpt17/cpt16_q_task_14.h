//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT16_Q_TASK_14_H
#define PLAYGROUND_CPT16_Q_TASK_14_H

#include <fstream>
#include <iomanip>

namespace cpt16_q_task_14 {
    void func() {
        std::ofstream of("cpt16_q_task_14.txt", std::ios::ate);
        int nameWidth = 20;
        int numWidth = 5;
        of << std::left << std::setw(nameWidth) << "char" << std::right << std::setw(numWidth) << sizeof(char) << std::endl;
        of << std::left << std::setw(nameWidth) << "unsigned char" << std::right << std::setw(numWidth) << sizeof(unsigned char) << std::endl;
        of << std::left << std::setw(nameWidth) << "short int" << std::right << std::setw(numWidth) << sizeof(short int) << std::endl;
        of << std::left << std::setw(nameWidth) << "unsigned short int" << std::right << std::setw(numWidth) << sizeof(unsigned short int) << std::endl;
        of << std::left << std::setw(nameWidth) << "int" << std::right << std::setw(numWidth) << sizeof(int) << std::endl;
        of << std::left << std::setw(nameWidth) << "unsigned int" << std::right << std::setw(numWidth) << sizeof(unsigned int) << std::endl;
        of << std::left << std::setw(nameWidth) << "long int" << std::right << std::setw(numWidth) << sizeof(long int) << std::endl;
        of << std::left << std::setw(nameWidth) << "unsigned long" << std::right << std::setw(numWidth) << sizeof(unsigned long) << std::endl;
        of << std::left << std::setw(nameWidth) << "float" << std::right << std::setw(numWidth) << sizeof(float) << std::endl;
        of << std::left << std::setw(nameWidth) << "double" << std::right << std::setw(numWidth) << sizeof(double) << std::endl;
        of << std::left << std::setw(nameWidth) << "long double" << std::right << std::setw(numWidth) << sizeof(long double) << std::endl;

        of.close();
    }
}

#endif //PLAYGROUND_CPT16_Q_TASK_14_H
