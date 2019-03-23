//
// Created by 倪震洋 on 2019-03-07.
//

#ifndef PLAYGROUND_MYFIRST_H
#define PLAYGROUND_MYFIRST_H

#include <cstdlib>
#include <iostream>

struct node {
    int data;
};

static void func() {
    struct node *new_node = nullptr;

    new_node = (struct node*)malloc(sizeof(struct node));
    memset(new_node, 5, sizeof(struct node));

    std::cout << new_node->data << std::endl;
}

#endif //PLAYGROUND_MYFIRST_H
