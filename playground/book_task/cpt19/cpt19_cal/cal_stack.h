//
// Created by schwarzeni on 2019-03-14.
//

#ifndef PLAYGROUND_CAL_STACK_H
#define PLAYGROUND_CAL_STACK_H

#include <vector>

namespace cpt19_cal {
    template<typename T>
    class CalStack {
    public:
        CalStack() {
            this->stack = std::vector<T>{};
        }

        void Push(const T &data) {
            this->stack.push_back(data);
        }

        T Top() {
            return this->stack.back();
        }

        bool Pop(T &data) {
            if (this->IsEmpty()) {
                return false;
            }
            data = this->stack.back();
            this->stack.pop_back();
            return true;
        }

        bool IsEmpty() {
            return this->stack.size() == 0;
        }

    private:
        std::vector<T> stack;

        int getLastIdx() {
            if (this->stack.size() == 0) {
                return 0;
            } else {
                return (int) this->stack.size() - 1;
            }
        }
    };
}

#endif //PLAYGROUND_CAL_STACK_H
