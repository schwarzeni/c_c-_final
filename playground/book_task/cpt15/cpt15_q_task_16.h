//
// Created by schwarzeni on 2019-03-12.
//

#ifndef PLAYGROUND_CPT15_Q_TASK_16_H
#define PLAYGROUND_CPT15_Q_TASK_16_H

#include "istream"
#include "ostream"
#include "iostream"

namespace cpt15_q_task_16 {
    class Complex {
        friend std::istream &operator>>(std::istream &in, Complex &complex) {
            // 输入格式
            // 3 + 8i
            // 3 - 8i
            // - 3
            // -3 + 8i
            // -8i
            // 8i
            // +8i
            while (in.peek() != EOF) {
                complex.ignoreWP(in);
                int cache;
                if (in.peek() == '+') {
                    in.ignore();
                    complex.ignoreWP(in);
                    in >> cache;
                    if (in.peek() == 'i') {
                        complex.imaginary = cache;
                        return in;
                    } else {
                        complex.real = cache;
                    }
                } else if (in.peek() == '-') {
                    in.ignore();
                    complex.ignoreWP(in);
                    in >> cache;
                    cache = -cache;
                    if (in.peek() == 'i') {
                        complex.imaginary = cache;
                        return in;
                    } else {
                        complex.real = cache;
                    }
                } else if (in.peek() - '0' >= 0 && in.peek() - '0' <= 9) {
                    in >> cache;
                    if (in.peek() == 'i') {
                        complex.imaginary = cache;
                        return in;
                    } else {
                        complex.real = cache;
                    }
                } else {
                    in.clear(std::ios::failbit);
                    return in;
                }
            }
            return in;
        }

        friend std::ostream &operator<<(std::ostream &out, const Complex &complex) {
            if (complex.real == 0 && complex.imaginary == 0) {
                out << 0;
                return out;
            }


            if (complex.real != 0) {
                if (complex.real > 0) {
                    out << complex.real;
                } else {
                    out << "- " << -complex.real;
                }
            }

            if (complex.imaginary != 0) {
                if (complex.imaginary > 0) {
                    if (complex.real != 0) {
                        out << " + ";
                        out << complex.imaginary << "i";
                    } else {
                        out << complex.imaginary << "i";
                    }
                } else {
                    if (complex.real != 0) {
                        out << " - ";
                        out << -complex.imaginary << "i";
                    } else {
                        out << -complex.imaginary << "i";
                    }
                }
            }
            return out;
        }

    public:
        Complex() {
            this->real = 0;
            this->imaginary = 0;
        }

    private:
        int real;
        int imaginary;

        void ignoreWP(std::istream &in) {
            while (in.peek() == ' ') {
                in.ignore();
            }
        }
    };

    void func() {
        Complex complex;
        std::cin >> complex;
        std::cout << complex;
    }
}

#endif //PLAYGROUND_CPT15_Q_TASK_16_H
