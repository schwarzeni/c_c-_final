//
// Created by schwarzeni on 2019-03-22.
//

#ifndef PRACTICE_TASK_2013_TASK3_3_H
#define PRACTICE_TASK_2013_TASK3_3_H

#include <fstream>
#include <iostream>
#include <cctype>

// 这里仅展示读取数据，不使用 std::string
// 默认读取的都是正数
namespace task_2013_task3_3 {
    void func() {
        const char kCircle = 'C';
        const int kCircleSize = 3;
        const char kTri = 'T';
        const char kTriSize = 3;
        const char kRec = 'R';
        const char kRecSize = 4;

        const int kEnd = -1000;

        const char filename[] = "task_2013_task3_3.txt";
        std::fstream fs(filename, std::ios::in);

        int numCache = 0;
        int numLen = 0;
        int dataSize = 0;
        int dataNumCache = 0;
        int dataCache[5];
        char ch;


        char mode = 'x';
        int currentDataSize = 0;
        while (1) {
            fs >> ch;
            if (ch == kCircle) {
                mode = ch;
                dataSize = kCircleSize;
                currentDataSize = kCircleSize;
                std::cout << "开始读取圆形数据" << std::endl;
            } else if (ch == kRec) {
                mode = ch;
                dataSize = kRecSize;
                currentDataSize = kRecSize;
                std::cout << "开始读取正方形数据" << std::endl;
            } else if (ch == kTri) {
                mode = ch;
                dataSize = kTriSize;
                currentDataSize = kTriSize;
                std::cout << "开始读取三角形形数据" << std::endl;
            } else if (ch == ';' || ch == ',' || fs.eof()) {
                    // 整理数据，清空缓存
                    dataCache[dataNumCache] = numCache;
                    dataCache[dataNumCache + 1] = kEnd;
                    dataNumCache++;
                    dataSize--;
                    numCache = 0;
                    numLen = 0;

                // 判断是否获取了一个完整数据
                if (dataSize == 0) {
                    // 获取了一个完整的数据
                    std::cout << mode << " ";
                    for (int i = 0; kEnd != dataCache[i]; i++) {
                        std::cout << dataCache[i] << " ";
                    }
                    std::cout << std::endl;

                    // 清空数据缓存
                    dataCache[0] = kEnd;
                    dataNumCache = 0;
                    dataSize = currentDataSize;

                    // 如果到了文件末尾则退出
                    if (fs.eof()) break;
                }
                // 如果是数字类型的字符
            } else if (std::isdigit(ch)) {
                int data = ch - '0';
                numCache = numCache * 10 + data;
                numLen++;
            }
        }
    }
}

#endif //PRACTICE_TASK_2013_TASK3_3_H
