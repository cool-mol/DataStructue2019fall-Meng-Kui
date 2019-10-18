//
// Created by zl l on 2019-10-17.
//

#include "Stack.h"
Stack::Stack(){
    elem = nullptr;
    currentLength = 0;
}

Stack::~Stack(){}

char Stack::pop(){
    char tmp = elem->letter;
    Node *p = elem;
    elem = elem->next;
    delete p;
    currentLength --;
    return tmp;
}

void Stack::push(const char &c){
    Node* tmp = new Node(c, elem);
    elem = tmp;
    currentLength ++;
}

bool Stack::isEmpty() {
    return (elem == nullptr);
}

char Stack::top(){
    return elem->letter;
}

void printRPN(const char* cal){
    Stack stack1;
    bool isOneNumber = false;
    int index = 0;
    while(cal[index] != '\0'){
        switch(cal[index]){
            case '(':
                isOneNumber = false;
                stack1.push(cal[index]);
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if(isOneNumber) cout << '\b' << cal[index] << ' ';
                else cout << cal[index] << ' ';
                isOneNumber = true;
                break;
            case ')':
                while(!stack1.isEmpty() && stack1.top() != '('){
                    cout << stack1.pop() << ' ';
                }
                stack1.pop();
                isOneNumber = false;
                break;
            case '+':
            case '-':
                while(!stack1.isEmpty() && stack1.top() != '(' ){
                    cout << stack1.pop() << ' ';
                }
                stack1.push(cal[index]);
                isOneNumber = false;
                break;
            case '*':
            case '/':
                while(!stack1.isEmpty()&& stack1.top() != '(' && stack1.top() != '+' && stack1.top() != '-') {
                    cout << stack1.pop() << ' ';
                }
                isOneNumber = false;
                stack1.push(cal[index]);
                break;



        }
        index ++;
    }
    while(!stack1.isEmpty()){
        cout << stack1.pop() << ' ';
    }
    cout << endl;
}

