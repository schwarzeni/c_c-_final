//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT21_16_H
#define PLAYGROUND_CPT21_16_H

// 是否为1024的倍数
namespace book_task_q_cpt21_18 {
    bool multiple(int number) {
        bool isMultiple = true;
        for (int i = 0, mask = 1; i < 10; i++, mask <<= 1)
            if ((number & mask) != 0) {
                isMultiple = false;
                break;
            }
        return isMultiple;
    }

    void func() {
        std::cout << multiple(512) << std::endl;
        std::cout << multiple(1024) << std::endl;
        std::cout << multiple(2048) << std::endl;
    }
}

#endif //PLAYGROUND_CPT21_16_H
