//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT17_HANDLEFILE_H
#define PLAYGROUND_CPT17_HANDLEFILE_H

#include <fstream>
#include <iostream>

namespace cpt17_handlefile {
    void WriteFile() {
        std::ofstream os("clients.txt", std::ios::app);

        if (!os) {
            std::cerr << "File could not be opened" << std::endl;
            exit(1);
        }

        int account;
        std::string name;

        std::cout << "> ";
        // 检查是否为fail
        while (std::cin >> account >> name) {
            if (std::cin.peek() == '#') {
                std::cin.clear(std::ios::failbit);
            } else {
                os << account << ' ' << name << std::endl;
                std::cout << "> ";
            }
        }
        os.close();
    }

    void ReadFile() {
        std::ifstream is("clients.txt", std::ios::in);

        if (!is) {
            std::cerr << "File could not be opened" << std::endl;
            exit(1);
        }

        int account;
        std::string name;

        while (is >> account >> name) {
            std::cout << std::left << std::setw(10) << account << std::right << std::setw(13) << name << std::endl;
        }

        is.close();
    }


    void func() {
        WriteFile();
    }

}


#endif //PLAYGROUND_CPT17_HANDLEFILE_H
