#include <iostream>

void sum(int numberOne, int numberTwo);
bool greater(int numberOne, int numberTwo);
bool process_and_operations(bool a, bool b);

int main() {
    float numberOne, numberTwo;
    bool a, b;

    std::cout << "Please Enter Two Numbers to Proceed: \n";
    std::cin >> numberOne >> numberTwo;

    sum(numberOne, numberTwo);

    if (greater(numberOne, numberTwo)) {
        std::cout << "Number One is Greater than Number Two \n";
    } else if (numberOne < numberTwo) {
        std::cout << "Number One is Less than Number Two \n";
    } else {
        std::cout << "Both Numbers Are Equal. \n";
    }

    std::cout << "Enter Values to Proceed: ONLY CHOOSE BETWEEN 0 or 1 \n";
    std::cin >> a >> b;

    if (process_and_operations(a, b)) {
        std::cout << "Successful \n";
    }

    return 0;
}

void sum(int numberOne, int numberTwo){
    std::cout << "Sum: " << numberOne + numberTwo << std::endl;
}

bool greater(int numberOne, int numberTwo){
    return numberOne > numberTwo;
}

bool process_and_operations(bool a, bool b){
    std::cout << "And: " << (a && b) << std::endl;
    std::cout << "Or: " << (a || b) << std::endl;
    std::cout << "It is Not A: " << (!a) << std::endl;
    std::cout << "It is Not B: " << (!b) << std::endl;

    return true;

}