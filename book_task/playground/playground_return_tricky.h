//
// Created by schwarzeni on 2019-03-17.
//

#ifndef BOOK_TASK_PLAYGROUND_RETURN_TRICKY_H
#define BOOK_TASK_PLAYGROUND_RETURN_TRICKY_H

namespace playground_return_tricky {
    template<typename T>
    class Stack {
    public:
        explicit Stack(int size) : size(size), top(0) {
            this->arr = new T(size);
        }

        T pop() {
            if (this->size < 0) {
                throw "pop on emply stack";
            }
            // !!!!! 自减并不会执行
            return this->arr[this->size--];
        }

        void push(T data) {
            if (this->top == this->size) {
                throw "push on full stack";
            }
            this->arr[(this->top)++] = data;
        }

    private:
        T *arr;
        int size;
        int top;
    };

    void func() {
        Stack<int> stack(23);
        stack.push(2);
        stack.push(1);
        stack.push(3);
        stack.pop();
        stack.pop();
    }
}

#endif //BOOK_TASK_PLAYGROUND_RETURN_TRICKY_H
