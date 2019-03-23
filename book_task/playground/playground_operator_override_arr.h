//
// Created by schwarzeni on 2019-03-17.
//

#ifndef BOOK_TASK_PLAYGROUND_OPERATOR_OVERRIDE_H
#define BOOK_TASK_PLAYGROUND_OPERATOR_OVERRIDE_H

#include <iostream>
#include <sstream>
#include <algorithm>

namespace playground_operator_override {
    template<typename T>
    class MyArr {
    public:
        explicit MyArr(int size) : size(size) {
            this->arr = new T(size);
            // 初始化
            for (int i = 0; i < this->size; i++) {
                this->arr[i] = 0;
            }
        }

        template<class>
        class Ref {
        public:
            Ref(MyArr *outer, int idx) : myArr(outer), idx(idx) {}

            // 这是get方法
            operator T() {
                if (this->idx < 0 || this->idx >= this->myArr->size) {
                    throw std::out_of_range("获取数组值时越界");
                }
                return this->myArr->arr[this->idx];
            }

            // 这是set方法
            Ref &operator=(T data) {
                if (this->idx < 0 || this->idx >= this->myArr->size) {
                    throw std::out_of_range("设置数组值时越界");
                }
                this->myArr->arr[this->idx] = data;
                return *this;
            }

        private:
            MyArr *myArr;
            int idx;
        };

        Ref<T> operator[](int idx) {
            return Ref<T>(this, idx);
        }

        ~MyArr() {
            delete[] this->arr;
        }

    private:
        T *arr;
        int size;
    };

    void func() {
        MyArr<int> arr(4);

        arr[0] = 2;
        arr[2] = 3;
        int arr2 = arr[2];
//        std::cout << arr << std::endl;
//        std::cout << arr[2] << std::endl;

//        arr[0] = 2;
//        arr[1] = 3;
//        arr[2] = 4;
//        arr[3] = 5;
//        std::cout << arr << std::endl;
//
//        MyArr<int> otherArr(6);
//        otherArr = arr;
//        std::cout << otherArr << std::endl;
    }
}

#endif //BOOK_TASK_PLAYGROUND_OPERATOR_OVERRIDE_H
