//
// Created by zl l on 2019-10-17.
//

#ifndef PROBLEM3_STACK_H
#define PROBLEM3_STACK_H
#include <iostream>
using namespace std;
class Stack{
private:
    struct Node{
        char letter;
        Node *next;
        Node(char l, Node* n = nullptr):letter(l), next(n){}
        Node():next(nullptr){}
        ~Node(){}
    };
    Node* elem;
    int currentLength;
public:
    Stack();
    ~Stack();
    char pop();
    void push(const char &c);
    bool isEmpty();
    char top();
};

void printRPN(const char* cal);
bool checkRight(const char* cal);
#endif //PROBLEM3_STACK_H
