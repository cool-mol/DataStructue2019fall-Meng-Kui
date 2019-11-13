//
// Created by zl l on 2019-11-11.
//

#ifndef PROBLEM2_PRIORITYQUEUE_H
#define PROBLEM2_PRIORITYQUEUE_H

#include <iostream>

using namespace std;

class priorityQueue {
private:
    int currentSize;
    int *array;
    int maxSize;
    int type;

    void doubleSpace();

    void buildHeap();

    void percolateDown(int hole);

public:
    priorityQueue(int capacity = 100) {
        array = new int[capacity];
        maxSize = capacity;
        currentSize = 0;
    }

    priorityQueue(const int data[], int size, int T); //1为最小堆 2为最大堆

    ~priorityQueue() { delete[] array; }

    bool isEmpty() const { return currentSize == 0; }

    void enQueue(const int &x);

    int deQueue();

    int getHead() { return array[1]; }

    int *getArray() { return array; }

    bool isEmpty() {
        return currentSize == 0;
    }

    int getLength() { return currentSize; }
};

#endif //PROBLEM2_PRIORITYQUEUE_H
