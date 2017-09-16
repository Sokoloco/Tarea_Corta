//
// Created by luis on 15/09/17.
//

#ifndef TAREA_CORTA_LINKEDLIST_H
#define TAREA_CORTA_LINKEDLIST_H
#include <iostream>
#include "llNode.h"

template <class T>
class LinkedList {
private:
    Node<T>* first;
    Node<T>* last;
    int size;
public:
    LinkedList() {
        first = NULL;
        last = NULL;
        size = 0;
    }

    void add(T data) {
        if (!first) {
            Node<T>* first = new Node<T>(data);
            last = first;
        } else {
            if (last == first) {
                last = new Node<T>(data);
                first->setNext(last);
            } else {
                Node<T> *insdata = new Node<T>(data);
                last->setNext(insdata);
                last = insdata;
            }
        }
        size++;
    }
    void remove(T data) {
        if (!first)return;
        if (first == last && first->getData() == data)
            first = last = NULL;
        else if (first->getData() == data)
            first = first->getNext();
        else {
            Node<T>* curr = first, *bhnd = curr;
            while (curr != NULL) {
                if (curr->getData() == data) {
                    bhnd->setNext(curr->getNext());
                    delete(curr);
                }
                bhnd = curr;
                curr = curr->getNext();
            }
        }
    }
    Node<T>* search(T value){
        Node<T>* curr = first;
        while(curr != NULL){
            if(curr->getData() == value) return curr;
            curr = curr->getNext();
        }
        return NULL;
    }
};

#endif //TAREA_CORTA_LINKEDLIST_H
