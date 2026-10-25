#include "StackLinkedList.h"

StackLinkedList::StackLinkedList() {
    top = nullptr;
}

bool StackLinkedList::isEmpty() {
    return top == nullptr;
}

void StackLinkedList::push(char c) {
    Node* newNode = new Node;
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char StackLinkedList::pop() {
    if (isEmpty()) {
        return '\0';
    }

    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;

    return poppedValue;
}

char StackLinkedList::peek() {
    if (isEmpty()) {
        return '\0';
    }

    return top->data;
}

StackLinkedList::~StackLinkedList() {
    while (!isEmpty()) {
        pop();
    }
}

bool checkBalancedLinkedList(const std::string& expression) {
    StackLinkedList stack;

    for (char c : expression) {

        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {

            if (stack.isEmpty())
                return false;

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