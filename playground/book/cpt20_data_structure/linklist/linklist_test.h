//
// Created by schwarzeni on 2019-03-14.
//

#ifndef PLAYGROUND_LINKLIST_TEST_H
#define PLAYGROUND_LINKLIST_TEST_H

#include "linklist.h"

namespace cpt20_data_structure_linklist_test {
    void func() {
        cpt20_data_structure_linklist::List<int> list{};
        list.insertAtFront(1);
        list.insertAtFront(2);
        list.insertAtFront(3);
        list.insertAtFront(4);
        list.insertAtBack(5);
        list.insertAtBack(6);
        list.insertAtBack(7);
        list.insertAtBack(8);
        list.print();
        int data;
        list.removeFromFront(data);
        list.print();
        list.removeFromFront(data);
        list.print();
        list.removeFromFront(data);
        list.print();
        list.removeFromBack(data);
        list.print();
        list.removeFromBack(data);
        list.print();
        list.removeFromBack(data);
        list.print();
    }
}

#endif //PLAYGROUND_LINKLIST_TEST_H
