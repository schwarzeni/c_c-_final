//
// Created by schwarzeni on 2019-03-22.
//

#ifndef PRACTICE_TASK_2013_7_H
#define PRACTICE_TASK_2013_7_H

#include <cctype>
#include <cstring>
#include <iostream>
#include <iomanip>


namespace task_2013_7 {

    const int kWordSize = 1000;
    const int kMax = 1000;
    const int kNoFound = -1;

    // 是否为标点符号
    inline bool isPunc(char &c) {
        return (c == '!' || c == '.' || c == ',');
    }

    // 是否为字母（包括+）
    inline bool isWChar(char &c) {
        return (std::isalnum(c) == 1 || c == '+');
    }

    // 是否为空格
    inline bool isBlank(char &c) {
        return std::isblank(c) == 1;
    }

    // 检查字符是否已经存在于map中
    inline int hasWord(char word[], char wordMap[][kWordSize], int &size) {
        for (int i = 0; i < size; i++) {
            if (std::strcmp(word, wordMap[i]) == 0) {
                return i;
            }
        }
        return kNoFound;
    }


    void func() {

        // 缓存字符
        char wordCache[kWordSize];
        // 缓存字符的长度
        int wordCacheCount = 0;
        // 记录单词
        char keyMap[kMax][kWordSize];
        // 记录单词出现的个数
        int numMap[kMax] = {0};
        // 记录单词出现次数
        int wordCount = 0;

        const char *str = "Welcome to C++ world ! Happy birthday to you. This is the weather report across the world for tomorrow , talk about it in pairs following the model below.";
        int totalLength = (int) std::strlen(str);

        for (int i = 0; i < totalLength; i++) {
            char currentChar = *(str + i);
            // 判断是否为字母
            // 如果是则加入缓存，修改两个变量

            // 一下两者情况需要清空字符缓存，加入map
            // 如果是标点则直接加入
            // 如果是空白则逃过

            if (isWChar(currentChar)) {
                wordCache[wordCacheCount++] = currentChar;
            } else {
                if (wordCacheCount != 0) {
                    wordCache[wordCacheCount] = '\0';
                    int idx = hasWord(wordCache, keyMap, wordCount);
                    if (idx != kNoFound) {
                        numMap[idx]++;
                    } else {
                        numMap[wordCount] = 1;
                        std::strcpy(keyMap[wordCount++], wordCache);
                    }
                    wordCacheCount = 0;
                }

                if (isBlank(currentChar)) continue;
                if (isPunc(currentChar)) {
                    wordCache[0] = currentChar;
                    wordCache[1] = '\0';
                    int idx = hasWord(wordCache, keyMap, wordCount);
                    if (idx != kNoFound) {
                        numMap[idx]++;
                    } else {
                        numMap[wordCount] = 1;
                        std::strcpy(keyMap[wordCount++], wordCache);
                    }
                }
            }
        }

        for (int i = 0; i < wordCount; i++) {
            std::cout << std::setw(10) << std::right << keyMap[i] << std::setw(5) << std::right << numMap[i] << std::endl;
        }
    }

}

#endif //PRACTICE_TASK_2013_7_H
