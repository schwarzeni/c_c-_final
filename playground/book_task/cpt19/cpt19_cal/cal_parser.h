//
// Created by schwarzeni on 2019-03-14.
//

#ifndef PLAYGROUND_CAL_PARSER_H
#define PLAYGROUND_CAL_PARSER_H

#include "cal_stack.h"
#include <string>

namespace cpt19_cal {

    bool isOperator(char opt) {
        return (opt == '*' || opt == '/' || opt == '%' || opt == '+' || opt == '-' || opt == '^');
    }

    bool isDigit(char opt) {
        return std::isdigit(opt) != 0;
    }

    bool precedence(char opt1, char opt2) {
        if (opt1 == '^') {
            return true;
        } else if (opt2 == '^') {
            return false;
        } else if (opt1 == '*' || opt1 == '/' || opt1 == '%') {
            return true;
        } else if (opt1 == '+' || opt1 == '-') {
            return !(opt2 == '*' || opt2 == '/' || opt2 == '%');
        }
        return false;
    }

    std::string parse(const std::string &str) {
        std::string result;
        cpt19_cal::CalStack<char> stack;
        for (const char ch : str) {
            if (cpt19_cal::isDigit(ch)) {
                // 是数字
                result.push_back(ch);
            } else if (cpt19_cal::isOperator(ch)) {
                // 是运算符
                while (true) {
                    char data = stack.Top();
                    if (!cpt19_cal::isOperator(data)) break;
                    if (cpt19_cal::precedence(data, ch)) {
                        stack.Pop(data);
                        result += data;
                    } else {
                        break;
                    }
                }
                stack.Push(ch);
            } else if (ch == '(') {
                // 是左括号
                stack.Push(ch);
            } else if (ch == ')') {
                // 是右括号
                char data;
                while (true) {
                    if (!stack.Pop(data)) break;
                    if (!cpt19_cal::isOperator(data)) break;
                    result += data;
                }
            } else if (ch == ' ') {
                continue;
            } else {
                throw std::invalid_argument(std::string("解析错误，未能识别字符: ") += ch);
            }
        }

        while (!stack.IsEmpty()) {
            char ch;
            stack.Pop(ch);
            result += ch;
        }

        return result;
    }
}

#endif //PLAYGROUND_CAL_PARSER_H
