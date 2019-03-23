//
// Created by schwarzeni on 2019-03-12.
//

#ifndef PLAYGROUND_CPT15_Q_TASK_14_H
#define PLAYGROUND_CPT15_Q_TASK_14_H

#include <ostream>
#include <istream>
#include <iostream>

namespace cpt15_q_task_14 {
    class PhoneNumber {
    public:
        friend std::ostream &operator<<(std::ostream &os, const cpt15_q_task_14::PhoneNumber &phoneNumber) {
            os << "(" << phoneNumber.areaCode << ")" << phoneNumber.exchange
               << "-" << phoneNumber.line << "\n";
            return os;
        }

        friend std::istream &operator>>(std::istream &is, cpt15_q_task_14::PhoneNumber &phoneNumber) {
            is.getline(phoneNumber.phone, 15);

            // 验证长度
            if (strlen(phoneNumber.phone) != 14) {
                is.clear(std::ios::failbit);
            }

            // 验证格式 (...) -
            if (phoneNumber.phone[0] != '(' || phoneNumber.phone[4] != ')'
                || phoneNumber.phone[9] != '-') {
                is.clear(std::ios::failbit);
            }

            // 验证区号和交换号
            if (phoneNumber.phone[1] == '0' || phoneNumber.phone[6] == '0' ||
                phoneNumber.phone[1] == '1' || phoneNumber.phone[6] == '1') {
                is.clear(std::ios::failbit);
            }

            if (!is.fail()) {
                int loop;
                // 进行相关值的初始化
                for (loop = 0; loop <= 2; loop++) {
                    phoneNumber.areaCode[loop] = phoneNumber.phone[loop + 1];
                    phoneNumber.exchange[loop] = phoneNumber.phone[loop + 6];
                }
                phoneNumber.areaCode[loop] = phoneNumber.exchange[loop] = '\0';

                for (loop = 0; loop <= 3; loop++) {
                    phoneNumber.line[loop] = phoneNumber.phone[loop + 10];
                }
                phoneNumber.line[loop] = '\0';
            } else {
                std::cerr << "Invalid phone number entered.\n";
                exit(1);
            }
            return is;
        }

        PhoneNumber() {
            this->phone[0] = '\0';
            this->areaCode[0] = '\0';
            this->exchange[0] = '\0';
            this->line[0] = '\0';
        }

    private:
        char phone[15]{};
        char areaCode[4]{};
        char exchange[4]{};
        char line[5]{};
    };
}

#endif //PLAYGROUND_CPT15_Q_TASK_14_H
