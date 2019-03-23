//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_DATE_H
#define PLAYGROUND_DATE_H

#include <ctime>
#include <ostream>
#include <iostream>

namespace cpt10_data {
    class Data {
    public:
        Data() {
            struct tm *ptr;
            time_t t = std::time(0);
            ptr = std::localtime(&t);
            this->day = ptr->tm_mday;
            this->month = ptr->tm_mon + 1;
            this->year = ptr->tm_year + 1900;
        }

        friend std::ostream &operator<<(std::ostream &os, const cpt10_data::Data &data) {
            return os << data.year << " " << data.month << " " << data.day;
        }

    private:
        int month;
        int day;
        int year;
    };

    void func() {
        cpt10_data::Data data = cpt10_data::Data();
        std::cout << data << std::endl;
    }
}

#endif //PLAYGROUND_DATE_H
