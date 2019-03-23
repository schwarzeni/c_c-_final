//
// Created by schwarzeni on 2019-03-15.
//

#ifndef PLAYGROUND_CPT_22_STL_RELEVANCE_H
#define PLAYGROUND_CPT_22_STL_RELEVANCE_H

#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <iomanip>

typedef std::multiset<int, std::less<> > Ims;
typedef std::set<double, std::less<>> DoubleSet;
typedef std::multimap<int, double, std::less<>> Mmid;
typedef std::map<int, double, std::less<>> Mid;

namespace cpt_22_stl_relevance {

    // 一对一存储的map
    void map() {
        Mid pairs;

        pairs.insert(Mmid::value_type(15, 2.7));
        pairs.insert(Mmid::value_type(15, 99.3));
        pairs.insert(Mmid::value_type(15, 50.6));
        pairs.insert(Mmid::value_type(34, 24.7));
        pairs.insert(Mmid::value_type(32, 32.7));
        pairs.insert(Mmid::value_type(16, 277.7));
        pairs.insert(Mmid::value_type(5, 2.7654));
        pairs.insert(Mmid::value_type(156, 2.2327));

        pairs[15] = 4455.5544;

        // 打印数据
        for (Mmid::const_iterator iter = pairs.begin(); iter != pairs.end(); ++iter) {
            std::cout << std::setw(10) << iter->first << std::setw(20) << std::right << iter->second << std::endl;
        }

    }

    // 一对多存储的map
    void multimap() {
        Mmid pairs;

        pairs.insert(Mmid::value_type(15, 2.7));
        pairs.insert(Mmid::value_type(15, 99.3));
        pairs.insert(Mmid::value_type(15, 50.6));

        // 统计key对应的value个数
        std::cout << pairs.count(15) << std::endl;

        // 再次多插入一些值
        pairs.insert(Mmid::value_type(34, 24.7));
        pairs.insert(Mmid::value_type(32, 32.7));
        pairs.insert(Mmid::value_type(16, 277.7));
        pairs.insert(Mmid::value_type(5, 2.7654));
        pairs.insert(Mmid::value_type(156, 2.2327));

        // 打印数据
        for (Mmid::const_iterator iter = pairs.begin(); iter != pairs.end(); ++iter) {
            std::cout << std::setw(10) << iter->first << std::setw(20) << std::right << iter->second << std::endl;
        }

    }

    void set() {
        const int kSize = 5;
        double arr[kSize] = {7.5, 22.2, 18.3, 22.2, 100.8};
        DoubleSet doubleSet;

        doubleSet.insert(arr, arr + kSize);

        std::ostream_iterator<double> output(std::cout, " ");
        std::copy(doubleSet.begin(), doubleSet.end(), output);
        std::cout << std::endl;
    }

    // 可以重复的set
    void multiset() {
        const int kSize = 5;
        int arr[kSize] = {7, 22, 18, 22, 100};
        Ims intMutiset;

        // 当前没有相关数据
        std::cout << intMutiset.count(22) << std::endl;

        // 插入数据
        intMutiset.insert(22);
        intMutiset.insert(22);

        // 存在相关数据
        std::cout << intMutiset.count(22) << std::endl;

        // 遍历所有相关的数据
        Ims::const_iterator result;
        result = intMutiset.find(22);
        while (result != intMutiset.end()) {
            std::cout << *result << " ";
            result++;
        }
        std::cout << std::endl;

        // 插入数据
        intMutiset.insert(arr, arr + kSize);

        // 打印全部数据
        std::ostream_iterator<int> output(std::cout, " ");
        std::copy(intMutiset.begin(), intMutiset.end(), output);
        std::cout << std::endl;

        // 获取相同数据的范围
        std::cout << *(intMutiset.lower_bound(22)) << " "
                  << *(intMutiset.upper_bound(22)) << std::endl;
    }


    void func() {
//        multiset();
//        set();
//        multimap();
        map();
    }
}

#endif //PLAYGROUND_CPT_22_STL_RELEVANCE_H
