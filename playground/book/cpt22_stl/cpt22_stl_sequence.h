//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT22_STL_PLAYGROUND_H
#define PLAYGROUND_CPT22_STL_PLAYGROUND_H

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>

namespace cpt22_stl_sequence {
    void itera() {
        std::istream_iterator<int> inputInt(std::cin);
        int number1 = *inputInt;
        ++inputInt;
        int number2 = *inputInt;
        std::ostream_iterator<int> outputInt(std::cout);
        *outputInt = number1 + number2;
    }

    // list 使用
    void list() {
        const int kSize = 6;
        int array[kSize] = {1, 2, 3, 4, 5, 6};
        std::list<int> values;
        std::list<int> values2{10, 11, 12};

        values.push_front(1);
        values.push_front(2);
        values.push_back(3);
        values.push_back(4);

        std::ostream_iterator<int> output(std::cout, " ");
        std::copy(values.cbegin(), values.cend(), output);
        std::cout << std::endl;

//        values.splice(values.end(), values2);
        values.merge(values2);
        // assign
        // unique
        std::copy(values.cbegin(), values.cend(), output);
        std::cout << std::endl;
    }

    // vector 使用
    void vector() {
        const int kSize = 6;
        int array[kSize] = {1, 2, 3, 4, 5, 6};

        // 从数组中构造
        std::vector<int> integers(array, array + kSize);

        // 序列打印
        std::ostream_iterator<int> output(std::cout, " ");
        std::copy(integers.cbegin(), integers.cend(), output);
        std::cout << std::endl;

        // 首尾打印
        std::cout << integers.front() << " " << integers.back() << std::endl;

        //插入
        int myarray[] = {501, 502, 503};
        // 插入：连续插入
        integers.insert(integers.begin(), 2, 8888);
        // 插入：指定位置插入
        integers.insert(integers.end(), 99999);
        // 插入：插入数组
        integers.insert(integers.begin(), myarray, myarray + 3);
        // 插入：插入vector
        std::vector<int> otherVector{555, 666, 777};
        std::move(otherVector.begin(), otherVector.end(), std::back_inserter(integers));

        std::copy(integers.cbegin(), integers.cend(), output);
        std::cout << std::endl;

        integers.clear();
    }


    void func() {
        list();
    }
}

#endif //PLAYGROUND_CPT22_STL_PLAYGROUND_H
