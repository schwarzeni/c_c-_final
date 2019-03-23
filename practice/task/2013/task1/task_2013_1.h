//
// Created by schwarzeni on 2019-03-22.
//

#ifndef PRACTICE_TASK_2013_1_H
#define PRACTICE_TASK_2013_1_H

#include <cassert>

namespace task_2013_1 {
    // 最大公约数
    int zdgys(int data1, int data2) {

        assert(data1 > 0 && data2 > 0);
        if (data1 == data2) return data1;

        int result = data1 > data2 ? data2 : data1;

        for (; result > 1; result--) {
            if (data1 % result == 0 && data2 % result == 0) return result;
        }
        return result;
    }

    // 最小公倍数
    int zxgbs(int data1, int data2) {
        assert(data1 > 0 && data2 > 0);
        if (data1 == data2) return data1;

        int result = data1 > data2 ? data1 : data2;
        int max = data1 * data2;

        for (; result < max; result++) {
            if (result % data1 == 0 && result % data2 == 0) return result;
        }
        return result;
    }


    void func() {
        assert(zdgys(11, 11) == 11);
        assert(zdgys(3, 9) == 3);
        assert(zdgys(4, 6) == 2);

        assert(zxgbs(11, 11) == 11);
        assert(zxgbs(4, 6) == 12);
        assert(zxgbs(3, 8) == 24);
    }
}

#endif //PRACTICE_TASK_2013_1_H
