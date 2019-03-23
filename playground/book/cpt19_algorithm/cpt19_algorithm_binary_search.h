//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT19_ALGORITHM_BINARY_SEARCH_H
#define PLAYGROUND_CPT19_ALGORITHM_BINARY_SEARCH_H

#include <iostream>
#include <algorithm>
#include <vector>
#include "cpt19_algorithm_util.h"

namespace cpt19_algorithm_binary_search {
    class BinarySearch {
    public:
        // 初始化
        explicit BinarySearch(int vectorSize) {
//            std::srand((unsigned int) std::time(nullptr));
            for (int i = 0; i < 1; i++) {
//                int size = 10 + rand() % 2000000000000000;
//                int size = 2000000000;
//                  // 9s
//                int size = 20000000;
                  // 归并 96s
                  // 快排 80s
                int size = 200000000;
//                int size = 200;
                this->data = cpt19_algorithm_util::getData(size);
                this->size = size;

                time_t now = time(0);

                std::cout << "排序开始 .. " << std::endl;
                time_t nowSec = time(0);
//                this->mergeSort();
                this->quickSort();
                time_t nowSecEnd = time(0);
                std::cout << "排序完毕，使用使用秒数" << nowSecEnd - nowSec << "s, 正在验证...." << std::endl;
                if (!cpt19_algorithm_util::isSorted(this->data)) {
                    std::cout << "测试失败" << std::endl;
                    return;
                }
            }
            std::cout << "测试成功" << std::endl;

//            std::sort(data.begin(), data.end());
        }

        // 进行二分排序
        int binarySearch(int searchItem) const {
            int middle = this->size / 2;
            int left = 0;
            int right = this->size - 1;
            while (left <= right) {
                if (searchItem > this->data[middle]) {
                    left = middle + 1;
                    middle = (left + right) / 2;
                } else if (searchItem < this->data[middle]) {
                    right = middle - 1;
                    middle = (left + right) / 2;
                } else {
                    return middle;
                }
            }
            return -1;
        }

        // 显示元素
        void displayElements() const {
            this->displayElements_(0, (int) (this->data.size()));
        }

        // 归并排序
        void mergeSort() {
            this->mergeSort_(0, this->data.size());
        }

        // 快速排序
        void quickSort() {
//            this->data = std::vector<int>({75, 92, 102, 100, 91, 99, 100, 76});
//            this->size = 8;
            this->quickSort_(0, this->size);
        }

    private:
        int size;
        std::vector<int> data;

        void displayElements_(int offset, int len) const {
            auto it = (this->data.cbegin() + offset);
            auto itEnd = (this->data.cbegin() + offset + len);

            for (; it != itEnd; it++) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }

        // 归并排序
        void mergeSort_(int index, int len) {
            if (len == 1) return;

            int firstIdx = index;
            int middle = index + len / 2;
            int secondIdx = middle;

            int firstLen = middle - index;
            int secondLen = len - firstLen;

            mergeSort_(firstIdx, firstLen);
            mergeSort_(secondIdx, secondLen);

            int *arr = new int[len];
            int firstCurrentIdx = firstIdx;
            int secondCurrentIdx = secondIdx;
            int arrIdx = 0;

            while ((firstCurrentIdx - firstIdx + 1 <= firstLen)
                   && (secondCurrentIdx - secondIdx + 1 <= secondLen)) {
                if (this->data[firstCurrentIdx] > this->data[secondCurrentIdx]) {
                    arr[arrIdx] = this->data[secondCurrentIdx];
                    secondCurrentIdx++;
                } else {
                    arr[arrIdx] = this->data[firstCurrentIdx];
                    firstCurrentIdx++;
                }
                arrIdx++;
            }
            while (firstCurrentIdx - firstIdx + 1 <= firstLen) {
                arr[arrIdx] = this->data[firstCurrentIdx];
                firstCurrentIdx++;
                arrIdx++;
            }
            while (secondCurrentIdx - secondIdx + 1 <= secondLen) {
                arr[arrIdx] = this->data[secondCurrentIdx];
                secondCurrentIdx++;
                arrIdx++;
            }

            for (int i = 0, vIdx = index; i < len; i++, vIdx++) {
                this->data[vIdx] = arr[i];
            }
            delete[] arr;
        }

        // 快速排序
        void quickSort_(int startIdx, int size) {
            if (size <= 1) return;
            int middle = this->quickSort_partion_(startIdx, size);
            this->quickSort_(startIdx, middle - startIdx);
            this->quickSort_(middle + 1, size - middle + startIdx -1);
        }

        // 将指定数据放在中间
        int quickSort_partion_(int idx, int size) {

            int initLeft = idx;
            int initRight = idx + size - 1;

            int initdata = this->data[idx];

            int left = idx;
            int right = idx + size - 1;
            while (left < right) {
                while (this->data[right] >= initdata && right > left) {
                    right--;
                }
                if (this->data[right] < initdata) {
                    this->swap_(right, idx);
                    idx = right;
                }

                while (this->data[left] <= initdata && left < right) {
                    left++;
                }
                if (this->data[left] > initdata) {
                    this->swap_(left, idx);
                    idx = left;
                }
            }
            return idx;
        }

        void swap_(int firstIdx, int secIdx) {
            int tmp = this->data[firstIdx];
            this->data[firstIdx] = this->data[secIdx];
            this->data[secIdx] = tmp;
        }
    };

    void func() {
        cpt19_algorithm_binary_search::BinarySearch binarySearch(11);
//        binarySearch.displayElements();
//        binarySearch.mergeSort();
//        binarySearch.displayElements();

//        while (true) {
//            int data;
//            std::cin >> data;
//            if (data == -1) break;
//            std::cout << binarySearch.binarySearch(data) << std::endl;
//        }
    }
}

#endif //PLAYGROUND_CPT19_ALGORITHM_BINARY_SEARCH_H
