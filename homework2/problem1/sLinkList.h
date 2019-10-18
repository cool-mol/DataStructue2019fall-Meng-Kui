//
// Created by zl l on 2019-10-17.
//

#ifndef PROBLEM1_SLINKLIST_H
#define PROBLEM1_SLINKLIST_H
#include <iostream>
using namespace std;
class sLinkList{
private:
    struct Node{
        int data;
        Node* next;
        Node(int d, Node* n = nullptr):data(d),next(n){}
        Node():next(nullptr){}
        ~Node(){}
    };
    int currentLength;
    Node* head;
    Node* tail;
public:
    sLinkList();
    ~sLinkList();
    void pushBack(int num);
    void deleteN(Node* pre);
    void erase(int x, int y);
    void print();


};
#endif //PROBLEM1_SLINKLIST_H
