//
// Created by schwarzeni on 2019-03-12.
//

#ifndef PLAYGROUND_CONTENT_H
#define PLAYGROUND_CONTENT_H

#include <iostream>

namespace cpt_13_task {
    class CA
    {
    public:
        void f()
        {
            std::cout << "CA f()" << std::endl;
        }
        virtual void ff()
        {
            std::cout << "CA ff()" << std::endl;
            f();
        }
    };

    class CB : public CA
    {
    public :
        virtual void f()
        {
            std::cout << "CB f()" << std::endl;
        }
        void ff()
        {
            std::cout << "CB ff()" << std::endl;
            f();
            CA::ff();
        }
    };
    class CC : public CB
    {
    public:
        virtual void f()
        {
            std::cout << "C f()" << std::endl;
        }
    };

    void func() {
        CB b;
        CA *ap = &b;
        CC c;
        CB &br = c;
        CB *bp = &c;

        ap->f();
        std::cout << std::endl;

        b.f();
        std::cout << std::endl;

        br.f();
        std::cout << std::endl;

        bp->f();
        std::cout << std::endl;

        ap->ff();
        std::cout << std::endl;

        bp->ff();
        std::cout << std::endl;

    }
}

#endif //PLAYGROUND_CONTENT_H
