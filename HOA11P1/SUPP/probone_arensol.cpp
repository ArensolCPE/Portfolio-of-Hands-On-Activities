#include <iostream>
#include <cstdlib>
#include <ctime>

bool unique(int A[]) {
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (A[i] == A[j]) {
                std::cout << "Two or more numbers in the array are similar.\n";
                return false;
            }
        }
    }
    std::cout << "All numbers in the array are unique.\n";
    return true;
}

int main() {
    srand(time(0));
    int arr[10];

    std::cout << "The numbers in the array are: ";
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    unique(arr);

    return 0;
}