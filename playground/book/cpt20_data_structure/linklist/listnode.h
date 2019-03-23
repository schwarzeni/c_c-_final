//
// Created by schwarzeni on 2019-03-14.
//

#ifndef PLAYGROUND_LISTNODE_H
#define PLAYGROUND_LISTNODE_H

#include "linklist.h"

namespace cpt20_data_structure_linklist {

    template <typename NODE_TYPE> class List;

    template<typename NODE_TYPE>
    class ListNode {
        // 将封装类作为友元类
        friend class cpt20_data_structure_linklist::List<NODE_TYPE>;

    public:
        explicit ListNode(const NODE_TYPE &info) : data(info), nextPtr(nullptr) {}

        NODE_TYPE getData() const {
            return this->data;
        }

    private:
        NODE_TYPE data;
        ListNode<NODE_TYPE> *nextPtr;
    };
}

#endif //PLAYGROUND_LISTNODE_H
