//
// Created by schwarzeni on 2019-03-12.
//

#ifndef PLAYGROUND_CPT15_USERINPUT_H
#define PLAYGROUND_CPT15_USERINPUT_H

#include <iostream>
#include <iomanip>

namespace cpt15_userinput {
    void func() {
//        std::cout << "Before input eof=" << std::cin.eof() << std::endl;
//
//        int character;
//
//        while ((character = std::cin.get()) != EOF) {
//            std::cout.put(static_cast<char>(character));
//            std::cout << "put: ";
//        }
//
//        std::cout << "EOF=" << static_cast<char>(character) << std::endl;
//        std::cout << "cin.eof=" << std::cin.eof() << std::endl;


//        const int kNum = 80;
//        char buffer[kNum];
//
//        std::cout << "Enter a sentence" << std::endl;
////        std::cin.read( buffer, 20 );
//        std::cin.getline(buffer, 20);
//
//        std::cout.write(buffer, std::cin.gcount()-1);
//        std::cout << std::endl;
//
//        int num = 25;
//        std::cout << std::hex << num << std::endl;
//        std::cout << std::oct << num << std::endl;
//        std::cout << std::dec << num << std::endl;
//        std::cout << std::setbase(8) << num << std::endl;

//        std::cout << '\a' << std::endl;
//        int widthValue = 4;
//        char sentence[4];
//        std::cout << "Enter a sentence" << std::endl;
//        std::cin.width(5);
//
//        while ( std::cin >> sentence) {
//            std::cout.width(widthValue++);
//            std::cout << sentence << std::endl;
//            std::cin.width(5);
//        }

        double data = 23.43434343;
        std::cout << std::fixed << std::setprecision(3) << data << std::endl;
        double data2 = 34;
        std::cout << std::fixed << std::showpoint << 34.00000 << std::endl;
        std::cout << std::internal << std::fixed << std::noshowpoint << 34.00000 << std::endl;

        std::ios_base::fmtflags of = std::cout.flags();

        std::cout.fill('*');
        std::cout << std::setw(10) << "2233" << std::endl;
        std::cout << "2233" << std::setw(10) << std::setfill('%') << "3322" << std::endl;
        std::cout << std::internal << std::setw(10) << std::setfill('&') << std::hex << 17 << std::endl;
        std::cout.flags(of);
        std::cout << std::cout.flags() << std::internal << std::setw(10) << std::setfill('&') << std::hex << 17
                  << std::endl;
        std::cout << std::cout.flags() << std::setw(10) << std::setfill('&') << std::hex << 17 << std::endl;

        std::cerr << "error" << std::endl;
        std::clog << "awesome" << std::endl;


        char *name = new char[10];
        std::cin.getline(name, 10, '.');
        std::cout << name << std::endl;
    }
}

#endif //PLAYGROUND_CPT15_USERINPUT_H
