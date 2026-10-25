#include <iostream>

double computeDistance(double distanceOne, double distanceTwo, double distanceThree, double distanceFour) {
    double sumOne = distanceTwo - distanceOne;
    double sumTwo = distanceFour - distanceThree;
    return std::sqrt((sumOne * sumOne) + (sumTwo * sumTwo));
}

int main () {
    float distanceValue, distanceValueTwo, distanceValueA, distanceValueTwoB;

    std::cout << "Enter Distance Value and ValueA: " << std::endl;
    std::cin >> distanceValue >> distanceValueA;

    std::cout << "Enter Distance ValueTwo and ValueTwoB; " << std::endl;
    std::cin >> distanceValueTwo >> distanceValueTwoB;

    double result = computeDistance(distanceValue, distanceValueA, distanceValueTwo, distanceValueTwoB);
    std::cout << "Distance Between 2 Points is: " << result;

    return 0;
}