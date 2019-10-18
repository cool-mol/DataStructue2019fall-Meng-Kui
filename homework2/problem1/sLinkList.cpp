//
// Created by zl l on 2019-10-17.
//
#include "sLinkList.h"

sLinkList::sLinkList(){
    head = new Node();
    currentLength = 0;
    tail = head;
}


sLinkList::~sLinkList(){
    Node* tmp = head->next;
    while(tmp != nullptr) {
        delete head;
        head = tmp;
        tmp = tmp->next;
    }
}

void sLinkList::pushBack(int num){
    currentLength ++;
    Node* node = new Node(num);
    tail->next = node;
    tail = node;
}

void sLinkList::print(){
    cout << currentLength << endl;
    for(Node* node = head->next;node != nullptr; node = node->next){
        cout << node->data << ' ';
    }
}

void sLinkList::deleteN(Node* pre){
    Node *q;
    q = pre->next;
    pre->next = q->next;
    delete q;
    currentLength --;
}
void sLinkList::erase(int x, int y){
    Node* p,* q;
    p = head;
    q = head->next;
    while(q != nullptr){
        if(q->data >= x && q->data <= y){
            q = q->next;
            deleteN(p);
        }else{
            p = q;
            q = q->next;
        }
    }
}
