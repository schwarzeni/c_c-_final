//
// Created by schwarzeni on 2019-03-23.
//

#ifndef PLAYGROUND_FINAL_TASK_3_H
#define PLAYGROUND_FINAL_TASK_3_H

#include <fstream>
#include <cstring>
#include <iostream>
#include <cctype>

namespace final_task_3 {

    class selfString {
    public:

        static bool isCharacter(char data) {
            return (data - 'a' >= 0 && data - 'z' <= 0) || (data - 'A' >= 0 && data - 'Z' <= 0);
        }

        static bool isEqual(const char *str1, int str1Len, const char *str2, int str2Len) {
            if (str1Len != str2Len) return false;

            for (int i = 0; i < str1Len; i++) {
                if (str1[i] != str2[i]) return false;
            }
            return true;
        }

        friend bool find(const selfString &str1, const selfString &str2, char *result, int &len);

        selfString(const char fileName[]) {
            bool quitSignal = false;
            this->capacity = 1000;
            this->dataStr = new char[capacity];
            this->length = 0;
            std::fstream fs(fileName, std::ios::in);

            char tmp;
            char strCache[100];
            int strLen = 0;

            fs.get(tmp);
            do {
                // 需要处理最后一波字符串
                if (fs.eof()) {
                    quitSignal = true;
                }
                // 如果是字符，仅限26个英文字母，包括大小写
                if (selfString::isCharacter(tmp)) {
                    strCache[strLen] = tmp;
                    strLen++;
                } else {
                    // 如果是其他的东西，拼接字符串
                    // 复制到存储区域
                    if (strLen != 0) {
                        for (int i = this->length; i < this->length + strLen; i++) {
                            this->dataStr[i] = strCache[i - this->length];
                        }
                        this->length += strLen;
                        // 添加空格
                        this->dataStr[this->length] = ' ';
                        this->length += 1;
                        // 清空缓存
                        strLen = 0;
                        strCache[0] = '\0';
                    }
                }
                tmp = static_cast<char>(fs.get());
            } while (!quitSignal);
            // 添加结尾符
            this->dataStr[this->length - 1] = '\0';
            this->length -= 1;
            fs.close();
        }

        ~selfString() {
            delete this->dataStr;
        }


        friend std::ostream &operator<<(std::ostream &os, const selfString &self) {
            for (int i = 0; i < self.length; i++) {
                os << self.dataStr[i];
            }
            return os;
        }

    private:
        char *dataStr;
        int length;
        int capacity;
    };

    bool find(const selfString &str1, const selfString &str2, char *result, int &len) {
        // 第一个字符串的相关缓存
        char str1Cache[100];
        int str1CacheLen = 0;
        int str1Pt = 0;
        // 第二个字符串的
        char str2Cache[100];
        int str2CacheLen = 0;
        int str2Pt = 0;
        // 记录最长的字符串
        char maxStr[100];
        int maxLen = 0;
        char str1char = *(str1.dataStr + str1Pt);
        while (true) {
            if (selfString::isCharacter(str1char)) {
                // 添加字符串
                str1Cache[str1CacheLen] = str1char;
                str1Cache[str1CacheLen + 1] = '\0';
                str1CacheLen++;
            } else if (str1CacheLen != 0) {
                // 如果遇到空格，则进行比较
                char str2char = *(str2.dataStr + str2Pt);
                bool str2QuitSignal = false;
                do{
                    // 需要处理最后一波字符串
                    if (str2char == '\0') {
                        str2QuitSignal = true;
                    }
                    if (selfString::isCharacter(str2char)) {
                        str2Cache[str2CacheLen] = str2char;
                        str2Cache[str2CacheLen + 1] = '\0';
                        str2CacheLen++;
                    } else if (str2CacheLen != 0) {
                        // 对两个字符串进行比较
                        if (selfString::isEqual(str1Cache, str1CacheLen, str2Cache, str2CacheLen)) {
                            if (maxLen < str1CacheLen) {
                                std::strcpy(maxStr, str1Cache);
                                maxLen = str1CacheLen;
                            }
                        }
                        // 清空str2字符串
                        str2Cache[0] = '\0';
                        str2CacheLen = 0;
                    }
                    str2Pt++;
                    str2char = *(str2.dataStr + str2Pt);
                } while (!str2QuitSignal);
                // 清空str1字符串，重置字符串2缓存的相关数据
                str1Cache[0] = '\0';
                str1CacheLen = 0;
                str2Pt = 0;
            }
            if (str1char == '\0') break;
            str1Pt++;
            str1char = *(str1.dataStr + str1Pt);
        }
        std::cout << maxStr << std::endl;
        return false;
    }

    void func() {

        selfString str("final_task_3_1.txt");
        selfString str2("final_task_3_2.txt");

        int len = 0;
        final_task_3::find(str, str2, nullptr, len);
    }
}

#endif //PLAYGROUND_FINAL_TASK_3_H
