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

    void doubleSpace();

    void buildHeap();

    void percolateDown(int hole);

public:
    priorityQueue(int capacity = 100) {
        array = new int[capacity];
        maxSize = capacity;
        currentSize = 0;
    }

    priorityQueue(const int data[], int size);

    ~priorityQueue() { delete[] array; }

    bool isEmpty() const { return currentSize == 0; }

    void enQueue(const int &x);

    int deQueue();

    int getHead() { return array[1]; }

    int *getArray() { return array; }

    bool isEmpty() {
        return currentSize == 0;
    }
};

#endif //PROBLEM2_PRIORITYQUEUE_H
