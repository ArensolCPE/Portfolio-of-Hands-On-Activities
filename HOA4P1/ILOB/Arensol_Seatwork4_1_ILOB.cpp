#include <iostream>
#include <stack>

//Definition choice
//#define maxSize 10
//const int maxSize = 10;
//const maxSize_t = 10;

//global variables:
#define MaxSize 10
int stackArr[MaxSize];
int top = -1, newData;

//function prototype
//top. push, pop, isempty, isfull

//function prototype
bool isEmpty();
bool isFull();
void Top(); //the T is capital
void Display();
void Push();
void Pop();

int main() {
    while (true) {
        std::cout << "===================================\n";
        std::cout << "Stack operations: " << std::endl;
        std::cout << " [1] Push [2] Pop [3] isEmpty [4] isFull [5] Top [6] Display " << std::endl;
        int choice;
        std::cin >> choice; 
        switch (choice) {
            case 1: Push();
            break;
            case 2: Pop();
            break;
            case 3: std::cout << "is the stack empty? " << isEmpty() << std::endl;
            break;
            case 4: std::cout << "is the stack full? " << isFull() << std::endl;
            break;
            case 5: Top();
            break;
            case 6: Display();
            break;
            default: std::cout << "Invalid choice" << std::endl;
        }
    }   
    return 0;
}

//function definition
bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MaxSize-1);
}

void Top() {
    if(isEmpty()) {
        std::cout << "stack is empty" << std::endl;
        return;
    }
    //prints the top element
    std::cout << "The top element is: " << stackArr[top] << std::endl;
}

void Push() {
    if(isFull()) {
        std::cout << "stack overflow" << std::endl;
        return;
}
    std::cout << "what character do you want to push? ";
    std::cin >> newData;

    stackArr[++top] = newData;
}
void Pop() {
    //error checking
    if(isEmpty()) {
        std::cout << "stack underflow" << std::endl;
        return;
    }
    //display the item to be popped
    std::cout << "Popping: " << stackArr[top] << std::endl;
    //we remove the element from the stack
    top--;
}

void Display() {
    if(isEmpty()) {
        std::cout << "stack is empty" << std::endl;
        return;
    }
    std::cout << "Stack elements from top to bottom: ";
    for(int i = top; i >= 0; i--) {
        std::cout << stackArr[i] << std::endl;
    }
    std::cout << std::endl;
}