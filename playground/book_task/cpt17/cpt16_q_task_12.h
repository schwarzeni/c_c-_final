#include <utility>

//
// Created by schwarzeni on 2019-03-13.
//

#ifndef PLAYGROUND_CPT16_Q_TASK_12_H
#define PLAYGROUND_CPT16_Q_TASK_12_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

namespace cpt16_q_task_12 {
    class Tool {
    public:
        friend std::ostream &operator<<(std::ostream &os, const cpt16_q_task_12::Tool &tool) {

            os << std::left << std::setw(10) << tool.getIdx()
               << std::left << std::setw(20) << tool.getName()
               << std::left << std::setw(10) << tool.getCount()
               << std::left << std::setw(10) << std::fixed << std::setprecision(2) << tool.getPrice()
               << std::endl;

            return os;
        }

        friend std::istream &operator>>(std::istream &is, cpt16_q_task_12::Tool &tool) {
            int id, count;
            std::string name;
            double price;

            is >> id >> name >> count >> price;;

            if (is.peek() == '#') {
                is.ignore();
//                is.clear(std::ios::failbit);
            } else {
                tool.setIdx(id);
                tool.setName(name);
                tool.setCount(count);
                tool.setPrice(price);
            }
            return is;
        }

        int getIdx() const {
            return this->idx;
        }

        void setIdx(int idx) {
            this->idx = idx;
        }

        std::string getName() const {
            return this->name;
        }

        void setName(std::string name) {
            this->name = std::move(name);
        }

        int getCount() const {
            return count;
        }

        void setCount(int count) {
            Tool::count = count;
        }

        double getPrice() const {
            return price;
        }

        void setPrice(double price) {
            Tool::price = price;
        }

    private:
        int idx;
        std::string name;
        int count;
        double price;
    };

    std::string filename = "cpt16_q_task_12.txt";

    void Insert() {
        // TODO: idx去重
        std::ofstream of(filename, std::ios::app | std::ios::binary);

        while (true) {
            Tool tool{};
            std::cout << "Input info: " << std::endl;
            std::cin >> tool;
            if (std::cin.fail()) {
                break;
            }
            of.seekp(0, std::ios::end);
            of.write(reinterpret_cast< char * >(&tool), sizeof(cpt16_q_task_12::Tool));
        }
        std::cout << "输入完毕" << std::endl;
        of.close();
    }

    void Print() {
        std::ifstream is(filename, std::ios::in | std::ios::binary);
        if (!is) {
            std::clog << "No such file !" << std::endl;
            return;
        }

        int count = 0;
        while (!is.eof()) {
            cpt16_q_task_12::Tool tool{};
            is.seekg(sizeof(cpt16_q_task_12::Tool) * count);
            is.read(reinterpret_cast< char * >(&tool), sizeof(cpt16_q_task_12::Tool));
            if (is.eof()) break;
            std::cout << tool;

            count++;
        }
        is.close();
    }

    void Update() {
        int input;
        std::string tmp;
        std::cout << "Input Tool id: " << std::endl;
        std::cin >> tmp;
        std::cin >> input;

        std::ifstream is(filename, std::ios::in  | std::ios::binary);
        std::ofstream os(filename, std::ios::out | std::ios::binary);
        if (!is) {
            std::clog << "No such file !" << std::endl;
            return;
        }

        std::vector<cpt16_q_task_12::Tool> tools;

        int count = 0;
        cpt16_q_task_12::Tool tool{};
        while (!is.eof()) {
            is.seekg(sizeof(cpt16_q_task_12::Tool) * count);
            is.read(reinterpret_cast< char * >(&tool), sizeof(cpt16_q_task_12::Tool));
            if (is.eof()) {
                std::cout << "No Such Tool !" << std::endl;
                return;
            }
            if (tool.getIdx() == input) break;
            count++;
        }

        std::cout << "Selected info is: " << std::endl;
        std::cout << tool;
        std::cout << "Input new Info" << std::endl;
        std::cin >> tool;

        os.seekp(sizeof(cpt16_q_task_12::Tool) * count);
        os.write(reinterpret_cast<const char *>(&tool), sizeof(cpt16_q_task_12::Tool));

        std::cout << "Update Success !" << std::endl;

        is.close();
        os.close();
    }

    void Delete() {
        // .....
    }

    void func() {
//        Insert();
        Print();
        Update();
        Print();
    }

}

#endif //PLAYGROUND_CPT16_Q_TASK_12_H
