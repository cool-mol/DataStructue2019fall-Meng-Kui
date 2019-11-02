//
// Created by zl l on 2019-10-31.
//

#include "binaryTree.h"

void binaryTree::preOrderTra(int i, int *pre_order) {
    pre_order[count] = node[i][0];
    count++;
    if (node[i][1] == -1 && node[i][2] == -1) return;
    if (node[i][1] != -1) preOrderTra(node[i][1], pre_order);
    if (node[i][2] != -1) preOrderTra(node[i][2], pre_order);
}

void binaryTree::midOrderTra(int i, int *mid_order) {
    if (node[i][1] != -1) midOrderTra(node[i][1], mid_order);
    mid_order[count] = node[i][0];
    count++;
    if (node[i][1] == -1 && node[i][2] == -1) return;
    if (node[i][2] != -1) midOrderTra(node[i][2], mid_order);
}

void binaryTree::postOrderTra(int i, int *post_order) {
    if (node[i][1] != -1) postOrderTra(node[i][1], post_order);
    if (node[i][2] != -1) postOrderTra(node[i][2], post_order);
    post_order[count] = node[i][0];
    count++;
    if (node[i][1] == -1 && node[i][2] == -1) return;
}

void binaryTree::setCountZero() {
    count = 0;
}