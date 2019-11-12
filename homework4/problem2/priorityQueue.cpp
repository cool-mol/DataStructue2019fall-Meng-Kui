//
// Created by zl l on 2019-11-11.
//

#include "priorityQueue.h"
#include <iostream>

using namespace std;

void priorityQueue::doubleSpace() {
    int *tmp;
    tmp = new int[currentSize * 2];
    for (int i = 0; i < currentSize; i++) {
        tmp[i] = array[i];
    }
    delete array;
    array = tmp;
}

priorityQueue::priorityQueue(const int *data, int size) {
    currentSize = size;
    maxSize = 100;
    array = new int[maxSize];
    for (int i = 0; i < size; i++) array[i + 1] = data[i];
    buildHeap();
}

void priorityQueue::buildHeap() {
    for (int i = currentSize / 2; i > 0; i--)
        percolateDown(i);
}

void priorityQueue::percolateDown(int hole) {
    int child;
    int tmp = array[hole];
    for (; hole * 2 <= currentSize; hole = child) {
        child = hole * 2;
        if (child != currentSize && array[child + 1] < array[child])child++;
        if (array[child] < tmp) array[hole] = array[child]; else break;
    }
    array[hole] = tmp;
}

void priorityQueue::enQueue(const int &x) {
    if (currentSize == maxSize - 1) doubleSpace();
    int hole = ++currentSize;
    for (; hole > 1 && x < array[hole / 2]; hole /= 2)
        array[hole] = array[hole / 2];
    array[hole] = x;
}

int priorityQueue::deQueue() {
    int minItem;
    minItem = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
    return minItem;
}

int priorityQueue::findMin(int x) {
    int tmp = 0;
    int ret = 0;
    for (int i = 0; i < currentSize; i++) {
        if (array[i + 1] > tmp) tmp = array[i + 1];
    }
    for (int i = 0; i < currentSize; i++) {
        if (array[i + 1] >= x && array[i + 1] < tmp) {
            tmp = array[i + 1];
            ret = i + 1;
        }
    }
    return ret;
}

void priorityQueue::decreaseKey(int i, int value) {
    array[i] -= value;
    int tmp;
    for (; i > 1 && array[i / 2] > array[i]; i /= 2) {
        tmp = array[i];
        array[i] = array[i / 2];
        array[i / 2] = tmp;
    }

}

int *priorityQueue::getArray() {
    int *tmp;
    tmp = new int[currentSize];
    for (int i = 0; i < currentSize; i++) {
        tmp[i] = array[i + 1];
    }

    return tmp;
}
