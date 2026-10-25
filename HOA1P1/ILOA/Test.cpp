#include <iostream>

int main () {
    int *ptr = new int(10);

    std::cout << "New Integer: " << *ptr << std::endl;

    return 0;
}