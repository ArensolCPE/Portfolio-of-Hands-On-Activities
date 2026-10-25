#include "StackArray.h"

StackArray::StackArray() {
    top = -1;
}

bool StackArray::isEmpty() {
    return top == -1;
}

bool StackArray::isFull() {
    return top == MAX_SIZE - 1;
}

void StackArray::push(char c) {
    if (!isFull()) {
        arr[++top] = c;
    }
}

char StackArray::pop() {
    if (!isEmpty()) {
        return arr[top--];
    }
    return '\0';
}

char StackArray::peek() {
    if (!isEmpty()) {
        return arr[top];
    }
    return '\0';
}

bool checkBalancedArray(const std::string& expression) {
    StackArray stack;

    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (stack.isEmpty()) {
                return false;
            }
            char topChar = stack.pop();
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return stack.isEmpty();
}