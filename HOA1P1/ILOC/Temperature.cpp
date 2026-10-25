#include <iostream>

int main() {
    float celsius, kelvin, fahrenheit, sum;
    int choice;
    char answer;

    std::cout << "\n===================== Converter Menu =====================\n";
    std::cout << "Choose One Option to Use" << std::endl;

    std::cout << "1. " << "Celsius " << "to" << " Fahrenheit" << std::endl;
    std::cout << "2. " << "Fahrenheit " << "to" << " Celsius" << std::endl;
    std::cout << "3. " << "Celsius " << "to" << " Kelvin" << std::endl;
    std::cout << "4. " << "Kelvin " << "to" << " Fahrenheit" << std::endl;;
    std::cout << "5. " << "Exit Menu" << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "Enter a Value for Celsius: ";
        std::cin >> celsius;
        sum = (celsius * 9/5) + 32;
        std::cout << "Fahrenheit: " << sum << std::endl;
        break;
    case 2:
        std::cout << "Enter a Value for Fahrenheit: ";
        std::cin >> fahrenheit;
        sum = (fahrenheit - 32) * 5/9;
        std::cout << "Celsius: " << sum << std::endl;
        break;
    case 3:
        std::cout << "Enter a Value for Celsius: ";
        std::cin >> celsius;
        sum = (celsius + 273.15);
        std::cout << "Kelvin: " << sum << std::endl;
        break;
    case 4:
        std::cout << "Enter a Value for Kelvin: ";
        std::cin >> kelvin;
        sum = (kelvin - 273.15) * 9/5 + 32;
        std::cout << "Fahrenheit: " << sum << std::endl;
        break;
    case 5:
        std::cout << "Exit?(Y/N) \n";
        std::cin >> answer;
        if (answer == 'Y' || answer == 'Y')
        {
            std::cout << "You Have Successfully Left the Converter Menu! \n";
        } else {
            std::cout << "You Have Decided to Stay in the Converter Menu. \n";
        }
        break;
    default:
        std::cout << "Invalid." << std::endl;
        break;
    }

    return 0;
}