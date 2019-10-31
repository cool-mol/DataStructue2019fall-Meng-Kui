//
// Created by zl l on 2019-10-28.
//

#ifndef PROBLEM2_QUEUE_H
#define PROBLEM2_QUEUE_H

#include <iostream>

using namespace std;

struct point {
    int x;
    int y;

    point(const int &px, const int &py) : x(px), y(py) {}

    point() {}

    ~point() {}
};

class queue {
private:
    struct node {
        point p;
        node *next;

        node(const point &x, node *N = nullptr) : p(x), next(N) {}

        node() : next(nullptr) {}

        ~node() {}
    };

    node *front, *rear;

public:
    queue();

    ~queue();

    bool isEmpty();

    void enqueue(const point &x);

    point dequeue();

    point getHead();

    point getRear();
};

#endif //PROBLEM2_QUEUE_H
