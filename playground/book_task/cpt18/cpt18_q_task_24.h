//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT18_Q_TASK_24_H
#define PLAYGROUND_CPT18_Q_TASK_24_H

#include <iostream>
#include <iomanip>
#include <vector>

namespace cpt18_q_task_24 {
    void PrintLevel(std::string &strList, int level) {
        int middleIdx = level * 2 - 2;
        int width = (int) strList.size()/2 + 2 - level;
        std::cout.width(width);
//        std::cout << std::setw(;
        for (int i = middleIdx - level + 1; i < middleIdx; i++) {
            std::cout << strList[i];
        }
        std::cout << strList[middleIdx];
        for (int i = middleIdx - 1; i >= middleIdx - level + 1; i--) {
            std::cout << strList[i];
        }
        std::cout << std::endl;
    }

    void Print(std::string strList) {
        int level = (int) strList.size() / 2 + 1;
        for (int i = 1; i <= level; i++) {
            PrintLevel(strList, i);
        }
    }

    void func() {
        Print("abcdefghijklmnopqrstuvwxyz{}233");

    }
}

#endif //PLAYGROUND_CPT18_Q_TASK_24_H
