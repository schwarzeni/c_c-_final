//
// Created by schwarzeni on 2019-03-17.
//

#ifndef BOOK_TASK_CPT_6_Q_38_H
#define BOOK_TASK_CPT_6_Q_38_H

#include <iostream>
#include <stack>

namespace cpt_6_q_38_39 {
    void towers(int disks, int start, int end, int temp) {
        if (disks == 1) {
            std::cout << start << " --> " << end << std::endl;
        } else {
            towers(disks - 1, start, temp, end);

            std::cout << start << " --> " << end << std::endl;

            towers(disks - 1, temp, end, start);
        }
    }


    struct Quad {
        Quad(int _n, int _x, int _y, int _z) : _n(_n), _x(_x), _y(_y), _z(_z) {}

        int _n;  // 要移动的盘子数
        int _x, _y, _z; // 起始 中转 结束
    };

    void towers_iter(int disks, int start, int end, int temp) {
        std::stack<Quad> s;
        s.push(Quad(disks, start, temp, end));

        while (!s.empty()) {
            Quad q = s.top();
            s.pop();

            disks = q._n;
            start = q._x;
            temp = q._y;
            end = q._z;

            if (disks == 1) {
                std::cout << start << " --> " << end << std::endl;
            } else {
                s.push(Quad(disks - 1, temp, start, end));
                s.push(Quad(1, start, temp, end));
                s.push(Quad(disks - 1, start, end, temp));
//                s.push(Quad(disks - 1, start, end, temp));
//                s.push(Quad(1, start, temp, end));
//                s.push(Quad(disks - 1, temp, start, end));
            }
        }
    }

    void func() {
        towers(3, 1, 3, 2);
        std::cout << "=========" << std::endl;
        towers_iter(3, 1, 3, 2);
    }
}

#endif //BOOK_TASK_CPT_6_Q_38_H
