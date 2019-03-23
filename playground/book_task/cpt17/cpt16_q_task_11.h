//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT16_Q_TASK_11_H
#define PLAYGROUND_CPT16_Q_TASK_11_H

#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

namespace cpt16_q_task_11 {
    class Person {
    public:
        const std::string &getLastName() const {
            return lastName;
        }

        void setLastName(const std::string &lastName) {
            Person::lastName = lastName;
        }

        const std::string &getFirstName() const {
            return firstName;
        }

        void setFirstName(const std::string &firstName) {
            Person::firstName = firstName;
        }

        const std::string &getAge() const {
            return age;
        }

        void setAge(const std::string &age) {
            Person::age = age;
        }

        int getId() const {
            return id;
        }

        void setId(int id) {
            Person::id = id;
        }

    private:
        std::string lastName;
        std::string firstName;
        std::string age;
        int id;
    };


    void Print(std::vector<Person> persons) {
        for (const Person &p : persons) {
            std::cout << std::fixed << std::setw(10) << p.getId()
                      << std::right << std::setw(10) << p.getFirstName()
                      << std::right << std::setw(10) << p.getLastName()
                      << std::right << std::setw(5) << p.getAge() << std::endl;
        }
    }

    std::string kFileName = "cpt16_q_task_11.txt";

    void Init() {
        std::cout << kFileName << std::endl;
        std::ofstream fs(kFileName, std::ios::binary | std::ios::ate);
//        if (!fs) {
//            std::cerr << "File cannot be found!" << std::endl;
//            exit(1);
//        }
        int total = 10;
        int count = 0;
        srand((unsigned) time(NULL));
        while (count < total) {
            cpt16_q_task_11::Person p{};
            p.setLastName("unassigned");
            p.setFirstName("");
            p.setAge("0");
            p.setId(rand() / 1000);
            fs.seekp(count * sizeof(cpt16_q_task_11::Person));
            fs.write(reinterpret_cast< const char * > (&p), sizeof(cpt16_q_task_11::Person));

            count++;
        }
        fs.close();
    }

    void Read(int start, int len) {
        std::vector<Person> persons{};
        std::fstream fs(kFileName, std::ios::in | std::ios::binary);
        if (!fs) {
            std::cerr << "File cannot be found!" << std::endl;
            exit(1);
        }

        int count = 0;

        while (!fs.eof() && count < len) {
            fs.seekg(start + count * sizeof(cpt16_q_task_11::Person));
            cpt16_q_task_11::Person p{};

            fs.read(reinterpret_cast< char * > (&p), sizeof(cpt16_q_task_11::Person));
            if (fs.eof()) break;

            persons.push_back(p);
            count++;
        }
        Print(persons);
    }

    void Insert(int num) {
        std::ofstream is(kFileName, std::ios::in | std::ios::binary | std::ios::app);
        srand((unsigned) time(NULL));

        std::string firstName;
        std::string lastName;
        std::string age;

        std::cout << "请输入" << num << "个信息" << std::endl;

        for (int i = 0; i < num; i++) {
            std::cout << "第" << i + 1 << "个:" << std::endl;
            std::cin >> firstName >> lastName >> age;
            Person p{};
            p.setId(rand() % 1000);
            p.setFirstName(firstName);
            p.setLastName(lastName);
            p.setAge(age);
            is.seekp(0, std::ios::end);
            is.write(reinterpret_cast< const char * >(&p), sizeof(cpt16_q_task_11::Person));
        }
        is.close();
    }

    void Update() {
        std::fstream fs(kFileName, std::ios::in | std::ios::binary | std::ios::out);
        int id;
        std::cout << "Select a user By id" << std::endl;
        std::cin >> id;

        Person p{};
        int idx = 0;
        while (!fs.eof()) {
            fs.seekg(sizeof(cpt16_q_task_11::Person) * idx);
            fs.read(reinterpret_cast< char * >(&p), sizeof(cpt16_q_task_11::Person));
            if (fs.eof()) {
                std::clog << "No such user" << std::endl;
                return;
            }
            if (p.getId() == id) {
                break;
            }
            idx++;
        }

        std::cout << "当前用户信息" << std::endl;
        std::cout << std::fixed << std::setw(10) << p.getId()
                  << std::right << std::setw(10) << p.getFirstName()
                  << std::right << std::setw(10) << p.getLastName()
                  << std::right << std::setw(5) << p.getAge() << std::endl;

        std::cout << "请输入新的信息" << std::endl;
        std::string fn, ln, age;
        std::cin >> fn >> ln >> age;

        p.setFirstName(fn);
        p.setLastName(ln);
        p.setAge(age);

        fs.seekp(sizeof(cpt16_q_task_11::Person) * idx);
        fs.write(reinterpret_cast< const char * >(&p), sizeof(cpt16_q_task_11::Person));
        fs.close();
    }


    void func() {
//        Init();
//        Insert(2);
        Read(0, 1000);
        Update();
        Read(0, 1000);

    }

}

#endif //PLAYGROUND_CPT16_Q_TASK_11_H
