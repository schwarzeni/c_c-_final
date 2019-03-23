//
// Created by schwarzeni on 2019-03-14.
//

#ifndef PLAYGROUND_CAL_CALER_H
#define PLAYGROUND_CAL_CALER_H

#include <string>
#include "cal_stack.h"
#include "cal_parser.h"
#include <math.h>
#include <sstream>

namespace cpt19_cal {

    //TODO: 处理小数等
    int opt(int num1, int num2, char opt) {
        if (opt == '+') {
            return num1 + num2;
        } else if (opt == '-') {
            return num1 - num2;
        } else if (opt == '*') {
            return num1 * num2;
        } else if (opt == '/') {
            return num1 / num2;
        } else if (opt == '%') {
            return num1 % num2;
        } else if (opt == '^') {
            return (int) pow(num1, num2);
        } else {
            std::ostringstream errMsg;
            errMsg << "无法进行运算 " << num1 << " " << opt << " " << num2;
            throw std::invalid_argument(errMsg.str());
        }
    }

    int cal(std::string &expression) {
        cpt19_cal::CalStack<int> dataStack;
        for (const char ch : expression) {
            if (cpt19_cal::isDigit(ch)) {
                // TODO 处理二位数以上的
                dataStack.Push(ch - '0');
            } else if (cpt19_cal::isOperator(ch)) {
                int num1, num2;
                if (dataStack.Pop(num2) && dataStack.Pop(num1)) {
                    dataStack.Push(cpt19_cal::opt(num1, num2, ch));
                } else {
                    throw std::invalid_argument("不合法运算");
                }
            } else {
                throw std::invalid_argument("不合法运算");
            }
        }
        int result;
        if (!dataStack.Pop(result)) {
            throw std::invalid_argument("结果错误");
        }
        return result;
    }
}

#endif //PLAYGROUND_CAL_CALER_H
