//
// Created by schwarzeni on 2019-03-22.
//

#ifndef PRACTICE_TASK_2013_9_H
#define PRACTICE_TASK_2013_9_H

#include <ctime>
#include <random>
#include <iostream>
#include <fstream>

namespace task_2013_9 {
    void func() {
        const int kMin = 1;
        const int kMax = 3;
        const int kBinarySize = sizeof(int) * 8;
        const char kFileName[] = "result.txt";
        std::fstream fs(kFileName, std::ios::out);

        // 随机生成长度
        std::srand(time(0));
        int count = std::rand() % (kMax - kMin + 1) + kMin;

        // 获取数据，默认是整数
        int arr[count];
        std::cout << "请输入" << count << "个数" << std::endl;
        for (int i = 0; i < count; i++) {
            std::cin >> arr[i];
        }

        for (int i = 0; i < count; i++) {

            // 生成二进制
            int data = arr[i];
            char binary[kBinarySize + 1];
            for (int j = kBinarySize - 1; j >= 0; j--) {
                binary[j] = (data & 1 == 1) ? '1' : '0';
                data >>= 1;
            }
            binary[kBinarySize] = '\0';

            // 写入文件
            fs << binary << std::endl;
        }
        fs.close();
    }
}

#endif //PRACTICE_TASK_2013_9_H
