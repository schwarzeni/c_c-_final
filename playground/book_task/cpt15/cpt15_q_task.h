//
// Created by schwarzeni on 2019-03-12.
//

#ifndef PLAYGROUND_CPT15_Q_TASK_H
#define PLAYGROUND_CPT15_Q_TASK_H

#include <iostream>
#include <iomanip>
#include "cpt15_q_task_15.h"
#include "cpt15_q_task_16.h"
#include "cpt15_q_task_17.h"
#include "cpt15_q_task_18.h"

namespace cpt15_q_task {

    void t_15_6_a() {
        // 15.6 (a) 左对齐打印
        std::cout << std::setw(15) << std::left << 40000 << std::endl;
    }

    void t_15_6_b() {
        // 15.6 (b) 读取字符砖
        char *str = new char[100];
        std::cin >> (str);
        std::cout << str << std::endl;
    }

    void t_15_6_c() {
        // 15.6 (c) 打印200，有符号无符号
        const std::ios_base::fmtflags prevFlag = std::cout.flags();
        std::cout.setf(std::ios::showpos);
        std::cout  << 200 << std::endl;
        std::cout.flags(prevFlag);
        std::cout << 200 << std::endl;
    }

    void t_15_6_d() {
        // 15.6 (d) 十六进制
        std::cout << std::hex << std::showbase << 100 << std::endl;
    }

    void t_15_6_e() {
        // 读取str，p或10停止，取分隔符
        const int kLen = 10;
        char *str = new char[kLen];
        std::cin.getline(str, kLen, 'p');
        std::cout << str << std::endl;
    }

    void t_15_6_f() {
        // 打印 9位 1.234
        std::cout << std::setw(9) << std::setfill('0') << std::right << 1.234 << std::endl;
    }

    void t_15_7() {
        // 检查输入情况
        int integer;
        std::cin >> integer;
        std::cout << std::showbase << std::dec << integer << "\n"
                                   << std::oct << integer << "\n"
                                   << std::hex << integer << "\n";
    }

    void t_15_8() {
        // 指针强转，编译不通过
        const char *str = "test";
    }

    void t_15_9() {
        // 输出不同长度的浮点数
        int x = 12345;
        double y = 1.2345;
        for ( int loop = 0; loop <= 10; loop++ ) {
            std::cout << x << "  printed in a field of size " << std::setw( 2 )
                    << loop << " is " << std::setw( loop ) << x << '\n' << y
                    << " printed in a field of size " << std::setw( 2 )
                    << loop << " is " << std::setw( loop ) << y << '\n';
        }
    }

    void t_15_11() {
        // 获取输入字符串长度，并以其两倍宽显示
        std::string str;
        int strLen;

        std::cin >> str;

        strLen = (int)str.length();

        std::cout << std::setw( 2 * strLen ) << str << std::endl;
    }

    void t_15_12() {
        // 温度转换
        const std::ios_base::fmtflags prevFlag = std::cout.flags();

        double celsius;

        for ( int fahrenheit = 0; fahrenheit <= 212; fahrenheit++ ) {
            celsius = 5.0 / 9.0 * ( fahrenheit - 32 );
            std::cout << std::setw( 15 ) << std::noshowpos << fahrenheit << std::setw( 23 )
                    << std::setprecision( 3 ) << std::showpos << celsius << '\n';
        }
    }

    void t_15_13() {
        // 将引号作为字符串的一部分
        std::string str;
        std::cin >> str;
        std::cout << str << std::endl;
    }

    void run(void (*cb)()) {
        cb();
    }

    void func() {
        run(cpt15_q_task_18::func);
    }

}

#endif //PLAYGROUND_CPT15_Q_TASK_H
