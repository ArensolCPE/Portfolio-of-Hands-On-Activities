#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H

#include <iostream>
#include <string>

struct Node {
    char data;
    Node* next;
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList();
    bool isEmpty();
    void push(char c);
    char pop();
    char peek();
    ~StackLinkedList();
};

bool checkBalancedLinkedList(const std::string& expression);

#endif