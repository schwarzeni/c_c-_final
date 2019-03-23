//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT18_Q_TASK_19_H
#define PLAYGROUND_CPT18_Q_TASK_19_H

#include <iostream>

namespace cpt18_q_task_19 {

    void deleteBy( std::string &strRef, std::string deleteStr ) {
        unsigned long x = (int)strRef.find(deleteStr);

        while (x <= strRef.length()) {
            strRef.erase(x, 2);
            x = strRef.find(deleteStr);
        }
    }

    void func() {
        std::string str = "getElementBYid getbyID";

        deleteBy(str, "by");
        deleteBy(str, "BY");

        std::cout << str << std::endl;
    }
}

#endif //PLAYGROUND_CPT18_Q_TASK_19_H
