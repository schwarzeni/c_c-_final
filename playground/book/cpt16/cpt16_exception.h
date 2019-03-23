//
// Created by schwarzeni on 2019-03-12.
//

#ifndef PLAYGROUND_CPT16_EXCEPTION_H
#define PLAYGROUND_CPT16_EXCEPTION_H

#include <stdexcept>
#include "iostream"

namespace cpt16_exception {
    class DivideByZeroExpcetion : public std::runtime_error {
    public:
        DivideByZeroExpcetion() : runtime_error("attempted to divied by zero") {}
    };

    double quotient (int numerator, int denominator) {
        if (denominator == 0) {
//            throw DivideByZeroExpcetion();
            throw;
        }
        return static_cast< double > (numerator) / denominator;
    }

    void func() {
        int num1;
        int num2;
        double result;
        while (std::cin >> num1 >> num2) {
            try {
                result = quotient(num1, num2);
                std::cout << "result is "  << result << std::endl;
            } catch (DivideByZeroExpcetion &expcetion) {
                std::cout << expcetion.what() << std::endl;
            }
            std::cout << "\nend\n";
        }
    }
}

#endif //PLAYGROUND_CPT16_EXCEPTION_H
