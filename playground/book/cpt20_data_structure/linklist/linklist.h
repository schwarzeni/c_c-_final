//
// Created by schwarzeni on 2019-03-14.
//

#ifndef PLAYGROUND_LIST_H
#define PLAYGROUND_LIST_H

#include "listnode.h"
#include <iostream>

namespace cpt20_data_structure_linklist {


    template<typename NODE_TYPE>
    class List {
    public:
        List();

        ~List();

        void insertAtFront(const NODE_TYPE &);

        void insertAtBack(const NODE_TYPE &);

        bool removeFromFront(NODE_TYPE &);

        bool removeFromBack(NODE_TYPE &);

        bool isEmpty() const;

        void print() const;

    private:
        cpt20_data_structure_linklist::ListNode<NODE_TYPE> *firstPtr;
        cpt20_data_structure_linklist::ListNode<NODE_TYPE> *lastPtr;

        cpt20_data_structure_linklist::ListNode<NODE_TYPE> *getNewNode(const NODE_TYPE &);
    };

    template<typename NODE_TYPE>
    List<NODE_TYPE>::List() : firstPtr(nullptr), lastPtr(nullptr) {}

    template<typename NODE_TYPE>
    List<NODE_TYPE>::~List() {
        if (!this->isEmpty()) {
            auto currentPtr = this->firstPtr;
            while (currentPtr != nullptr) {
                auto tmpPtr = currentPtr;
                currentPtr = currentPtr->nextPtr;
                delete tmpPtr;
            }
        }
    }

    template<typename NODE_TYPE>
    void List<NODE_TYPE>::insertAtFront(const NODE_TYPE &data) {
        auto newNode = this->getNewNode(data);
        if (this->isEmpty()) {
            this->firstPtr = this->lastPtr = newNode;
        } else {
            newNode->nextPtr = firstPtr;
            firstPtr = newNode;
        }
    }

    template<typename NODE_TYPE>
    void List<NODE_TYPE>::insertAtBack(const NODE_TYPE &data) {
        auto newNode = this->getNewNode(data);
        if (this->isEmpty()) {
            this->firstPtr = this->lastPtr = newNode;
        } else {
            this->lastPtr->nextPtr = newNode;
            lastPtr = newNode;
        }
    }

    template<typename NODE_TYPE>
    bool List<NODE_TYPE>::removeFromFront(NODE_TYPE &data) {
        if (this->isEmpty()) {
            return false;
        }

        auto tmp = this->firstPtr;
        if (this->firstPtr == this->lastPtr) {
            this->firstPtr = this->lastPtr = nullptr;
        } else {
            this->firstPtr = this->firstPtr->nextPtr;
        }

        data = tmp->data;
        delete tmp;
        return true;
    }

    template<typename NODE_TYPE>
    bool List<NODE_TYPE>::removeFromBack(NODE_TYPE &data) {
        if (this->isEmpty()) {
            return false;
        }

        if (this->firstPtr == this->lastPtr) {
            data = this->firstPtr->data;
            delete this->firstPtr;
            this->firstPtr = this->lastPtr = nullptr;
        } else {
            auto currentNode = this->firstPtr;
            while (true) {
                if (currentNode->nextPtr == this->lastPtr) {
                    delete this->lastPtr;
                    this->lastPtr = currentNode;
                    currentNode->nextPtr = nullptr;
                    break;
                }
                currentNode = currentNode->nextPtr;
            }
        }
        return true;
    }

    template<typename NODE_TYPE>
    bool List<NODE_TYPE>::isEmpty() const {
        return this->firstPtr == nullptr || this->lastPtr == nullptr;
    }

    template<typename NODE_TYPE>
    void List<NODE_TYPE>::print() const {
        auto *tmp = this->firstPtr;
        while (tmp != nullptr) {
            std::cout << tmp->data << " ";
            tmp = tmp->nextPtr;
        }
        std::cout << std::endl;
    }

    template<typename NODE_TYPE>
    ListNode<NODE_TYPE> *List<NODE_TYPE>::getNewNode(const NODE_TYPE &data) {
        auto *node = new ListNode<NODE_TYPE>(data);
        return node;
    }


}

#endif //PLAYGROUND_LIST_H
