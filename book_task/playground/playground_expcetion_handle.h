//
// Created by schwarzeni on 2019-03-21.
//

#ifndef BOOK_TASK_PLAYGROUND_EXPCETION_HANDLE_H
#define BOOK_TASK_PLAYGROUND_EXPCETION_HANDLE_H

#include <stdexcept>
#include <iostream>

namespace playground_expcetion_handle {
    class MyLogicError : public std::logic_error {
    public:
        MyLogicError() : std::logic_error("自定义的错误") {}
    };

    class MyInvalidArgument : public std::invalid_argument {
    public:
        MyInvalidArgument() : std::invalid_argument("自定义的错误参数错误") {}
    };

    class MyLengthError : public std::length_error {
    public:
        MyLengthError() : std::length_error("自定义的长度错误") {}
    };

    class MyOutOfRange : public std::out_of_range {
    public:
        MyOutOfRange() : std::out_of_range("自定义的超出范围的错误") {}
    };

    void funcMayThrowException() {
        throw MyOutOfRange();
    }

    void errorFromException() {
        try {
            throw;
        } catch (MyOutOfRange const &e) {
            std::cout << e.what() << std::endl;
        } catch (MyInvalidArgument const &e) {
            std::cout << e.what() << std::endl;
        } catch (MyLengthError const &e) {
            std::cout << e.what() << std::endl;
        } catch (MyLogicError const &e) {
            std::cout << e.what() << std::endl;
        } catch (std::exception const &e) {
            std::cout << "Other error: " << e.what() << std::endl;
        }
    }

    void func() {
        try {
            funcMayThrowException();
        } catch (...) {
            errorFromException();
        }
    }
};

#endif //BOOK_TASK_PLAYGROUND_EXPCETION_HANDLE_H
