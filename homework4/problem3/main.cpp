#include <iostream>
#include "priorityQueue.h"

using namespace std;

int minBoxSize(int N, int *items, int capacity) {
    // 请构造并使用优先级队列类实现该函数
    priorityQueue Q(items, N);
    int sum = 0;
    int tmp;
    int *bag = new int[N];
    for(int i = 0;i < N;i ++){
        bag[i] = 0;
    }
    while(!Q.isEmpty()){
        tmp = Q.deQueue();
        for(int i = 0;i < N;i ++){
            if(bag[i] + tmp <= capacity){
                bag[i] += tmp;
                break;
            }
        }
    }
    for(int i = 0;bag[i] != 0;i ++){
        sum ++;
    }
    return sum;
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