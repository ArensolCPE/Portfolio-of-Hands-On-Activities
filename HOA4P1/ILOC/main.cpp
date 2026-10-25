#include <iostream>
#include <string>
#include "StackArray.h"
#include "StackLinkedList.h"
#include "StackArray.cpp"
#include "StackLinkedList.cpp"

int main() {
    int choice;
    std::string expression;
    bool balanced = false;

    std::cout << "================================\n" << std::endl;
    std::cout << "  The Balanced Symbol Checker\n" << std::endl;
    std::cout << "================================\n" << std::endl;
    std::cout << "1. Stack using array\n";
    std::cout << "2. Stack using linked list\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::cout << "Enter an expression: ";
    std::cin >> expression;

    switch (choice) {
    case 1:
        balanced = checkBalancedArray(expression);
        if (balanced) {
            std::cout << "The expression is VALID." << std::endl;
        } else {
            std::cout << "The expression is INVALID." << std::endl;
        }
        break;

    case 2:
        balanced = checkBalancedLinkedList(expression);
        if (balanced) {
            std::cout << "The expression is VALID." << std::endl;
        } else {
            std::cout << "The expression is INVALID." << std::endl;
        }
        break;

    default:
        std::cout << "Invalid choice." << std::endl;
        break;
    }

    return 0;
}