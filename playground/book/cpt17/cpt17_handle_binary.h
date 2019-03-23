//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT17_HANDLE_BINARY_H
#define PLAYGROUND_CPT17_HANDLE_BINARY_H

#include "iostream"
#include "fstream"

namespace cpt17_handle_binary {
    class Person {
    public:
        Person(std::string name, int age) : name(std::move(name)), age(age) {}

        Person() = default;

        std::string name;
        int age{};
    };

    void WriteFile() {
        std::string name;
        int age;

        std::ofstream os("client-data", std::ios::app | std::ios::binary);

        if (!os) {
            std::cerr << "File could not be opened." << std::endl;
            exit(1);
        }

        int numCount = 0;
        while (std::cin >> name >> age) {
            if (std::cin.peek() == '#' || std::cin.peek() == '#') {
                std::cin.clear(std::ios::failbit);
                os.flush();
            } else {
                Person p{name, age};
                os.seekp(numCount * sizeof(Person));
                os.write(reinterpret_cast< const char * > (&p), sizeof(Person));
                numCount++;
            }
        }

        os.close();
    }

    void ReadFile() {
        std::ifstream is("client-data", std::ios::in | std::ios::binary);

        if (!is) {
            std::cerr << "File could not be opened." << std::endl;
            exit(1);
        }

        Person p;
        while (!is.eof()) {
            is.read(reinterpret_cast< char * > (&p), sizeof(Person));
            if (is.eof()) {
                break;
            }
            std::cout << p.name << " " << p.age << std::endl;
        }
        is.close();
    }

    void func() {
//        WriteFile();
        ReadFile();
    }
}

#endif //PLAYGROUND_CPT17_HANDLE_BINARY_H
