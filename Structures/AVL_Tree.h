//
// Created by luis on 15/09/17.
//

#ifndef TAREA_CORTA_AVL_TREE_H
#define TAREA_CORTA_AVL_TREE_H
#include<iostream>

using namespace std;

template <class T> class AVL{

private:
    struct AVLNode{
        T data;
        AVLNode* left;
        AVLNode* right;
        int height;
    };
    AVLNode* root;

    AVLNode* insert(T x, AVLNode* t){
        if(t == NULL){
            t = new AVLNode;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if(x < t->data){
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            t->right = insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }

    AVLNode* singleRightRotate(AVLNode* &t) {
        AVLNode* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }

    AVLNode* singleLeftRotate(AVLNode* &t) {
        AVLNode* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    }

    AVLNode* doubleLeftRotate(AVLNode* &t) {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    AVLNode* doubleRightRotate(AVLNode* &t) {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    int height(AVLNode* t) {
        return (t == NULL ? -1 : t->height);
    }

    int getBalance(AVLNode* t) {
        if(t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

public:
    AVL(){
        root = NULL;
    }

    void insert(T x){
        root = insert(x, root);
    }
};
#endif //TAREA_CORTA_AVL_TREE_H
