//
// Created by zl l on 2019-10-17.
//

#ifndef PROBLEM2_SLINKSTRING_H
#define PROBLEM2_SLINKSTRING_H
#include <iostream>
using namespace std;
struct Node{
    char letter;
    Node *next;
    Node(char l, Node* n = nullptr):letter(l), next(n){}
    Node():next(nullptr){}
    ~Node(){}
};
class sLinkString{
private:

    Node* head,* tail;
    int wordLength;


public:
    sLinkString();
    ~sLinkString();
    void inputWord(char* word);
    void pushBack(char letter);
    void clear();
    void print();

friend void printSameSuffix(sLinkString &w1, sLinkString &w2); //友元函数
};
void printSameSuffix(sLinkString &w1, sLinkString &w2);


#endif //PROBLEM2_SLINKSTRING_H
