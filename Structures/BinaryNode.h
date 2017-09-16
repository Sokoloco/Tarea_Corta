//
// Created by luis on 15/09/17.
//

#ifndef TAREA_CORTA_AVL_NODE_H
#define TAREA_CORTA_AVL_NODE_H

#include <stddef.h>

template <class T> class BinaryNode {
public:
    BinaryNode<T> *parent, *left, *right;
    T data;
    BinaryNode(T ndata){
        parent = left = right = NULL;
        data = ndata;
    }
};
#endif //TAREA_CORTA_AVL_NODE_H
