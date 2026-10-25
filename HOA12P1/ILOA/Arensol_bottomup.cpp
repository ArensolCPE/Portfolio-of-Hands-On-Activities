#include <iostream>
#include <algorithm>
#include "bottomupdp.h"

int main()
{
    int ranVal[] = {5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 95, 99};

    std::cout << "Minimum Steps Using Bottom-Up DP" << std::endl;

    for (int n : ranVal)
    {
        std::cout << "Input: " << n
            << " | Result of the Min. Steps: " << getMinSteps(n)
            << std::endl;
    }

    return 0;
}
