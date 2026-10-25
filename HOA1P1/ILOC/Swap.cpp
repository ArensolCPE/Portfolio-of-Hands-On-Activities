#include <iostream>

int main() {
    float varA, varB, swap;

    std::cout << "Enter First Value: " << std::endl;
    std::cin >> varA;

    std::cout << "Enter Second Value: " << std::endl;
    std::cin >> varB;

    swap = varA;
    varA = varB;
    varB = swap;

    std::cout << "After Swapping " << "the " << "Values of Both Numbers Are: " << std::endl;
    std::cout << "First Value(Swapped): " << varA << std::endl;
    std::cout << "Second Value(Swapped): " << varB << std::endl;

    return 0;
}