//
// Created by schwarzeni on 2019-03-12.
//

#ifndef PLAYGROUND_TMP_STATIC_H
#define PLAYGROUND_TMP_STATIC_H

namespace cpt14_tmp_static {
    template<typename T>
    class TT {
    public:
        static int count;
    };
    template <>
    int cpt14_tmp_static::TT<int>::count = 23;

    template <>
    int cpt14_tmp_static::TT<double >::count = 23;
}

#endif //PLAYGROUND_TMP_STATIC_H
