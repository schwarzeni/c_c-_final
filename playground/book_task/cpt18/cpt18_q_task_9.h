//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT18_Q_TASK_9_H
#define PLAYGROUND_CPT18_Q_TASK_9_H

#include <iostream>

// 比较字符串

namespace cpt18_q_task_9 {

    // if ( ( ( s[ j ].rfind( "ay" ) == s[ j ].length() - 2 ) )
    //     ( s[ j ].rfind( "r" ) == s[ j ].length() - 1 ) )

    bool IsMatchStr(const std::string &str) {
        int stringSize = (int) str.size();
        const std::string arr[] = {"r", "ay"};
        for (const std::string &matchStr : arr) {
            int len = (int) matchStr.size();
            if (len > stringSize) continue;
            if (str == matchStr) {
                return true;
            } else if (str.substr((unsigned long) (stringSize - len), (unsigned long) len) == matchStr) {
                return true;
            }
        }
        return false;
    }

    void func() {
        const std::string arr[] = {"array", "arraz", "arrry", "y", "r"};
        for (const std::string &str : arr) {
            if (IsMatchStr(str)) {
                std::cout << str << std::endl;
            }
        }
    }
}

#endif //PLAYGROUND_CPT18_Q_TASK_9_H
