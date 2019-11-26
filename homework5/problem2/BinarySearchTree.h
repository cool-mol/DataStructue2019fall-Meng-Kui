//
// Created by zl l on 2019-11-25.
//

#ifndef PROBLEM2_BINARYSEARCHTREE_H
#define PROBLEM2_BINARYSEARCHTREE_H

#include <iostream>
#include <cstring>

using namespace std;

class BinarySearchTree {
private:

    struct BinaryNode {
        int key;
        char str[80];
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(int k, char *s, BinaryNode *lt = nullptr, BinaryNode *rt = nullptr) : key(k), left(lt),
                                                                                         right(rt) {
            strcpy(str, s);
        }
    };

    int count;
    int currentSize;
    BinaryNode *root;
public:

    BinarySearchTree() : count(0), currentSize(0), root(nullptr) {}

    ~BinarySearchTree();

    char *find(const int &x) const;

    void insert(const int &x, char *s);

    void remove(const int &x);

    void midOrder();

    void find_i(int x);

    void deleteInRange(int x, int y);

    void deleteLarger(int x);

    void deleteSmaller(int x);

private:

    void insert(const int &x, char *s, BinaryNode *&t);

    void remove(const int &x, BinaryNode *&t);

    char *find(const int &x, BinaryNode *t) const;

    void makeEmpty(BinaryNode *t);

    void midOrder(BinaryNode *t);

    void find_i(int *arr, BinaryNode *t);

    void deleteInRange(int x, int y, BinaryNode *t);

    void deleteLarger(int x, BinaryNode *t);

    void deleteSmaller(int x, BinaryNode *t);
};

#endif //PROBLEM2_BINARYSEARCHTREE_H
