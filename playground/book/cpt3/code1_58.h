//
// Created by 倪震洋 on 2019-03-09.
//

#ifndef PLAYGROUND_CODE1_H
#define PLAYGROUND_CODE1_H

#include <iostream>
#include <string>

namespace book_cpt3_1 {
    class GradeBook {
    public:
        void displayMsg(const std::string &msg) {
            std::cout << msg << std::endl;
        }

        const std::string &getName() const {
            return name;
        }

        void setName(const std::string &name) {
            GradeBook::name = name;
        }

    private:
        std::string name;
    };

    void func() {
        GradeBook gradeBook;
        std::string msg;
        std::cout << "Enter something" << std::endl;
        getline(std::cin, msg);
        gradeBook.displayMsg(msg);
    }
}

#endif //PLAYGROUND_CODE1_H
