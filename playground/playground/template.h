//
// Created by 倪震洋 on 2019-03-07.
//

#ifndef PLAYGROUND_TEMPLATE_H
#define PLAYGROUND_TEMPLATE_H

#include <iostream>

class Obj {
public:
    double data;

    double data_2;

    Obj(double data, double data_2) : data(data), data_2(data_2) {}


    double getData() const {
        return data;
    }

    void setData(double data) {
        Obj::data = data;
    }

    bool operator<(const Obj &rhs) const {
        return data < rhs.data;
    }

    bool operator>(const Obj &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Obj &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Obj &rhs) const {
        return !(*this < rhs);
    }

    bool operator==(const Obj &rhs) const {
        return data == rhs.data;
    }

    bool operator!=(const Obj &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Obj &obj) {
        os << "data: " << obj.data;
        return os;
    }

    virtual ~Obj() = default;
};


template<typename T, class G>
T foo(T *p, G g) {
    T tmp = *p + 1;
    std::cout << g << std::endl;
    return tmp;
}

template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]) {
    return strcmp(p1, p2);
}

void func_template() {
    int p = 23;
    double g = 2.3;
    int result = foo<int, double>(&p, g);
    std::cout << result << std::endl;

    const int result2 = compare("nzy", "lj");
    std::cout << result2 << std::endl;

}

#endif //PLAYGROUND_TEMPLATE_H
