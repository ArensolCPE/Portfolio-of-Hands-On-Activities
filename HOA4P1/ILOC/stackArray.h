#ifndef STACKARRAY_H
#define STACKARRAY_H
#include <iostream>
#include <string>

const int MAX_SIZE = 100;

class StackArray {
private:
    char arr[MAX_SIZE];
    int top;

public:
    StackArray();
    bool isEmpty();
    bool isFull(); 
    void push(char c);
    char pop();
    char peek();
};

bool checkBalancedArray(const std::string& expression);
#endif