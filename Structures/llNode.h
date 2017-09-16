//
// Created by luis on 15/09/17.
//

#ifndef TAREA_CORTA_LLNODE_H
#define TAREA_CORTA_LLNODE_H
#include <iostream>
template <class T>
class Node {
private:
    Node<T>* next;
    T data;
public:

    Node<T> (T data1) {
        next = NULL;
        data = data1;
    }

    Node<T>* getNext() {
        return next;
    }

    void setNext(Node<T> *newNode) {
        next = newNode;
    }

    bool compare(T compare) {
        return *data == compare;
    }

    bool hasnext() {
        return next != NULL;
    }

    T getData() {
        return data;
    }

    bool hasData() {
        return data == NULL;
    }
};
#endif //TAREA_CORTA_LLNODE_H
