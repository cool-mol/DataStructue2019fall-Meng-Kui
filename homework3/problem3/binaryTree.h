//
// Created by zl l on 2019-10-31.
//

#ifndef PROBLEM3_BINARYTREE_H
#define PROBLEM3_BINARYTREE_H

#include <iostream>

using namespace std;

class binaryTree {
private:
    int **node;
    int number;
    int count;
public:
    binaryTree(int **a, int n) : node(a), number(n) {}

    binaryTree() : node(nullptr) {}

    ~binaryTree() {}

    void preOrderTra(int i, int *pre_order);

    void midOrderTra(int i, int *pre_order);

    void postOrderTra(int i, int *pre_order);

    void setCountZero();
};

#endif //PROBLEM3_BINARYTREE_H
