//
// Created by luis on 15/09/17.
//

#ifndef TAREA_CORTA_BINARY_STREE_H
#define TAREA_CORTA_BINARY_STREE_H

#include <iostream>
#include "BinaryNode.h"
template <class T> class Tree {
private:
    BinaryNode<T>* root;
    void walk(BinaryNode<T> *node) {
        if(node == NULL)
            return;
        walk(node->left);
        std::cout<<node->data<<std::endl;
        walk(node->right);
    }
    BinaryNode<T>* search(T value, BinaryNode<T>* current){
        if( current == NULL) return NULL;
        if(value == current->data) return current;
        if(value < current->data) search(value,current->left);
        else search(value,current->right);
    }
    void transplant(BinaryNode<T>* u,BinaryNode<T>* v){
        if (u -> parent == NULL) root = v;
        else if (u -> parent -> left == u) {
            u -> left = v;
        } else if (u -> parent -> right == u) {
            u -> right = v;
        }
        if (v != NULL) v -> parent = u -> parent;
    }

    T minval(BinaryNode<T>* curnt){
        BinaryNode<T>* curr1 = curnt;
        while(curr1->left != NULL){
            curr1 = curr1->left;
        }
        return curr1->data;
    }
    void removeRoot(){
        if(root == NULL)return;
        BinaryNode<T>* delPtr = root;
        T rootKey = root->data;
        T smallestRight;
        if(root->right == NULL && root->left == NULL){
            root == NULL;
            delete delPtr;
        }else if(root->left == NULL && root->right != NULL){
            root = root->right;
            delPtr->right = NULL;
            delete(delPtr);
        }else if(root->left != NULL && root->right == NULL){
            root = root->left;
            delPtr->left = NULL;
            delete(delPtr);
        }else{
            smallestRight = minval(root->right);
            remove(smallestRight,root);
            root->data = smallestRight;
        }
    }
    void remove(BinaryNode<T>* parent,BinaryNode<T>* match,bool left){
        if(root==NULL)return;
        BinaryNode<T>* delptr;
        T matchKey = match->data;
        T smallestR;
        if(match->left == NULL && match->right== NULL){
            delptr = match;
            left ? parent->left = NULL: parent->right = NULL;
            delete delptr;
        }else if(match->left ==NULL && match->right != NULL){
            left ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            delptr = match;
            delete delptr;
        }else if(match->left !=NULL && match->right == NULL){
            left ? parent->left = match->left : parent->right = match->left;
            match->left = NULL;
            delptr = match;
            delete delptr;
        }else{
            smallestR =minval(match->right);
            remove(smallestR,match);
            match->data = smallestR;

        }
    }
    void remove(T value, BinaryNode<T>* parent){
        if(root == NULL)return;
        if(root->data == value) removeRoot();
        else{
            if(value < parent->data && parent->left != NULL){
                parent->left->data == value ?
                remove(parent,parent->left,true):
                remove(value,parent->left);
            }else if(value > parent->data && parent->right != NULL){
                parent->right->data == value ?
                remove(parent,parent->right,false):
                remove(value,parent->right);
            }
        }
    }
public:
    Tree() {
        root = NULL;
    }
    void walk() {
        walk(root);
    }
    void insert(T data){
        if (!root)
            root = new BinaryNode<T>(data);
        else {
            BinaryNode<T> *current = root,*parent = root;
            bool left = false;
            while(current != NULL){
                parent = current;
                if(data <=current->data){
                    current = current->left;
                    left = true;
                }
                else{
                    current = current->right;
                    left = false;
                }
            }
            BinaryNode<T>* newN = new BinaryNode<T>(data);
            newN->parent = parent;
            if(left) parent->left = newN;
            else parent->right = newN;
        }
    }
    BinaryNode<T>* search(T value){
        return search(value,root);
    }
    void remove(T value){
        remove(value,root);
    }
};

#endif //TAREA_CORTA_BINARY_STREE_H
