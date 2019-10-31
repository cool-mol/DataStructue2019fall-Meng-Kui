//
// Created by zl l on 2019-10-28.
//

#include "Queue.h"


queue::queue() {
    front = rear = nullptr;
}


queue::~queue() {
    node *tmp;
    while (front != nullptr) {
        tmp = front;
        front = front->next;
        delete tmp;
    }
}


bool queue::isEmpty() {
    return (front == nullptr);
}


point queue::dequeue() {
    node *tmp = front;
    point val = front->p;
    front = front->next;
    if (front == nullptr) rear = front;
    delete tmp;

    return val;
}


void queue::enqueue(const point &x) {
    if (rear == nullptr) {
        front = rear = new node(x);
    } else {
        rear->next = new node(x);
        rear = rear->next;
    }
}


point queue::getHead() {
    return front->p;
}

point queue::getRear() {
    return rear->p;
}