#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <bitset>
#include <fstream>
#include "playground/playground_expcetion_handle.h"
#include "playground/playground_placement_new.h"
#include "playground/playground_operator_override_arr.h"
#include "playground/playground_inline.h"

class BaseBase {
public:
//    virtual void print() {
//        std::cout << "BaseBase print" << std::endl;
//    };
    virtual void print() {
        std::cout << "BaseBase print" << std::endl;
    };

    virtual ~BaseBase() = default;;
    int data;

};

class Child : public BaseBase {
public:
    void print() override {
        std::cout << "Child print" << std::endl;
    }

    ~Child() override {
        std::cout << " child 销毁" << std::endl;
    };
};

template<typename T>
class Tmp : public Child {
};

template<typename T>
class TmpChild : public Tmp<T> {
private:
};

template<typename T>
T compare(T a1, T a2) {
    std::cout << typeid(a1).name() << " " << typeid(a2).name() << std::endl;
    return a1;
}

template<>
double compare(double a1, double a2) {
    const char *a1_type = typeid(a1).name();
    std::cout << typeid(a1).name() << " " << typeid(a2).name() << std::endl;
    return a1 > a2 ? a1 : a2;
}

class Str {
public:
    Str() {
        this->data = "";
        std::cout << "Call 构造函数" << std::endl;
    }

    Str &append(const char *str) {
        std::string tmp(str);
        data.insert(data.length(), str);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Str &str) {
        os << str.data.c_str();
        return os;
    }

    ~Str() {
        std::cout << "Call 析构函数" << std::endl;
    }

private:
    std::string data;
//    std::cout << data. << std::endl;
};

int main() {
    int arr[] = {1,2,35,3,3,24,5,4,3,2};
    std::sort(std::begin(arr), std::end(arr), [](int f, int l) {return f > l;});
    std::for_each(std::begin(arr), std::end(arr), [](int &i){std::cout << i << " ";});
    return 0;
}

// unique_ptr make_unique container
// shared_ptr make_shared
