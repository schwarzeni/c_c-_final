//
// Created by schwarzeni on 2019-03-11.
//

#ifndef PLAYGROUND_INLINE_H
#define PLAYGROUND_INLINE_H

namespace playground_inline {
    class I {
    public:
        I(int a, int b) : a_(a), b_(b) {}

        int max();

    private:
        int a_;
        int b_;
    };

    inline int playground_inline::I::max() {
        return this->a_ > this->b_ ? this->a_ : this->b_;
    }
}

#endif //PLAYGROUND_INLINE_H
