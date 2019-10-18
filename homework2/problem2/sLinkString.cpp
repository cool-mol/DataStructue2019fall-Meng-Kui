//
// Created by zl l on 2019-10-17.
//

#include "sLinkString.h"

sLinkString::sLinkString(){
    head = new Node;
    tail = head;
    wordLength = 0;
}

sLinkString::~sLinkString(){}

void sLinkString::inputWord(char* word){
    Node* p = head;
    int i = 0;
    while(word[i] != '\0'){
        p->next = new Node(word[i]);
        p = p->next;
        i ++;
        wordLength ++;
    }
    tail = p;
}

void sLinkString::pushBack(char letter){
    tail->next = new Node(letter);
    tail = tail->next;
}

void sLinkString::clear(){
    Node* p = head->next;
    Node* q = p;
    while(p != nullptr){
        q = p->next;
        delete p;
        p = q;
    }
    head->next = nullptr;
    tail = head;
}

void sLinkString::print() {
    for(Node* p = head->next;p != nullptr;p = p->next){
        cout << p->letter;
    }
    cout << endl;
}

void printSameSuffix(sLinkString &w1, sLinkString &w2){
    Node* p1,* p2;
    p1 = w1.head->next;
    p2 = w2.head->next;
    sLinkString suffix;
    int tmp = w1.wordLength - w2.wordLength;
    if(tmp > 0)
        while(tmp > 0){
            p1 = p1->next;
            tmp --;
        }
    if(tmp < 0)
        while(tmp < 0){
            p2 = p2->next;
            tmp ++;
        }
    while(p1 != nullptr && p2 != nullptr){
        if(p1->letter == p2->letter) {
            suffix.pushBack(p1->letter);
            p1 = p1->next;
            p2 = p2->next;
        }else{
            suffix.clear();
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    suffix.print();

}




