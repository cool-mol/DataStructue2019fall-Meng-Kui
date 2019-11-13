#include <iostream>
#include "priorityQueue.h"

using namespace std;

int minBoxSize(int N, int *items, int capacity) {
    // 请构造并使用优先级队列类实现该函数
    priorityQueue Q(items, N, 2);
    int *B = new int[100];
    priorityQueue bag(B, 0, 1);
    int tmp;
    while(!Q.isEmpty()){
        tmp = Q.deQueue();
        if(bag.isEmpty()){
            bag.enQueue(tmp);
            continue;
        }

        if(tmp + bag.getHead() <= capacity){
            tmp += bag.getHead();
            bag.deQueue();
            bag.enQueue(tmp);
            continue;
        }

        if(tmp + bag.getHead() > capacity){
            bag.enQueue(tmp);
        }

    }

    return bag.getLength();
}

int main() {
    /* initialize */
    int N;
    cin >> N;
    int *items = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> items[i];
    }
    int capacity;
    cin >> capacity;
    /* test */
    cout << minBoxSize(N, items, capacity) << endl;

    /* free memory */
    delete[]items;
    return 0;
}