//
// Created by schwarzeni on 2019-03-12.
//

#ifndef PLAYGROUND_CPT15_Q_TASK_15_H
#define PLAYGROUND_CPT15_Q_TASK_15_H

#include "istream"
#include "ostream"
#include "iostream"

namespace cpt15_q_task_15 {
    class Point {
        friend std::ostream &operator<<(std::ostream &out, const Point &p) {
            out << "( " << p.xC << " , " << p.yC << " ) ";
            return out;
        }

        friend std::istream &operator>>(std::istream &in, Point &p) {
            p.ignoreWP(in);

            if (in.peek() != '(') {
                in.clear(std::ios::failbit);
                return in;
            } else {
                in.ignore();
            }

            p.ignoreWP(in);

            in >> p.xC;

            p.ignoreWP(in);

            if (in.peek() != ',') {
                in.clear(std::ios::failbit);
                return in;
            } else {
                in.ignore();
            }

            p.ignoreWP(in);

            in >> p.yC;

            p.ignoreWP(in);

            if (in.peek() != ')') {
                in.clear(std::ios::failbit);
                return in;
            } else {
                in.ignore();
            }

            return in;
        }

    private:
        int xC;
        int yC;

        void ignoreWP(std::istream &in) {
            while (in.peek() == ' ') {
                in.ignore();
            }
        }
    };

    void func() {
        Point p{};
        std::cin >> p;
        if (std::cin.fail()) {
            std::cout << "failed" << std::endl;
        } else {
            std::cout << p << std::endl;
        }
    }
}

#endif //PLAYGROUND_CPT15_Q_TASK_15_H
