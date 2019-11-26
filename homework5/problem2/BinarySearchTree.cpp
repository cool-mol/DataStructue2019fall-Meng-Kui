//
// Created by zl l on 2019-11-25.
//

#include "BinarySearchTree.h"

BinarySearchTree::~BinarySearchTree() {
    makeEmpty(root);
}

char *BinarySearchTree::find(const int &x) const {
    return find(x, root);
}

void BinarySearchTree::insert(const int &x, char *s) {
    insert(x, s, root);
}

void BinarySearchTree::remove(const int &x) {
    remove(x, root);
}


void BinarySearchTree::insert(const int &x, char *s, BinaryNode *&t) {
    if (t == nullptr) {
        t = new BinaryNode(x, s, nullptr);
        currentSize++;
    } else if (x <= t->key)insert(x, s, t->left);
    else if (t->key < x)insert(x, s, t->right);
}

void BinarySearchTree::remove(const int &x, BinaryNode *&t) {
    if (t == nullptr) return;
    if (x < t->key) remove(x, t->left);
    else if (t->key < x) remove(x, t->right);
    else if (t->left != nullptr && t->right !=
                                   nullptr) {
        BinaryNode *tmp = t->right;
        while (tmp->left != nullptr) tmp = tmp->left;
        t->key = tmp->key;
        remove(t->key, t->right);
    } else {
        BinaryNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
        currentSize--;
    }
}


char *BinarySearchTree::find(const int &x, BinaryNode *t) const {

    if (t == nullptr) {
        return nullptr;
    }
    if (t->key == x)return t->str;
    if (x < t->key) return find(x, t->left);
    else return find(x, t->right);
}

void BinarySearchTree::makeEmpty(BinaryNode *t) {
    if (t == nullptr) return;
    else {
        makeEmpty(t->left);
        makeEmpty(t->right);
    }
    delete t;
    currentSize = 0;
}

void BinarySearchTree::midOrder() {
    midOrder(root);
}

void BinarySearchTree::midOrder(BinaryNode *t) {
    if (t == nullptr) return;

    midOrder(t->left);
    cout << t->key << ' ';
    midOrder(t->right);
}

void BinarySearchTree::find_i(int x) {
    int *array;
    count = 0;
    array = new int [currentSize]{0};
    find_i(array, root);
    cout << array[currentSize - x] << endl;
    delete []array;
}

void BinarySearchTree::deleteInRange(int x, int y) {
    deleteInRange(x, y, root);
}

void BinarySearchTree::deleteLarger(int x) {
    deleteLarger(x, root);
}

void BinarySearchTree::deleteSmaller(int x) {
    deleteSmaller(x, root);
}

void BinarySearchTree::find_i(int *arr, BinaryNode *t) {


    if(t->left != nullptr) find_i(arr, t->left);
    arr[count] = t->key;
    count ++;
    if(t->left == nullptr && t->right == nullptr) return;
    if(t->right != nullptr)find_i(arr, t->right);
}

void BinarySearchTree::deleteInRange(int x, int y, BinaryNode *t) {
    if (t == nullptr) return;

    deleteInRange(x,y, t->left);
    deleteInRange(x,y, t->right);
    if (t->key >= x && t->key <= y) remove(t->key);
}

void BinarySearchTree::deleteLarger(int x, BinaryNode *t) {
    if (t == nullptr) return;

    deleteLarger(x, t->right);
    if (x <= t->key) remove(t->key);
}

void BinarySearchTree::deleteSmaller(int x, BinaryNode *t) {
    if (t == nullptr) return;

    deleteSmaller(x, t->left);
    if (x >= t->key) remove(t->key);
}