#include <iostream>
#include <algorithm>
#include "memoization.h"

int main()
{
    int ranVal[] = {5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 95, 99};

    std::cout << "Minimum Steps Using Memoization DP" << std::endl;

    for (int n : ranVal)
    {
        int memo[100];
        for (int i = 0; i <= n; i++)
        {
            memo[i] = -1;
        }

        std::cout << "Input: " << n
                << " | Result of the Min. Steps: " << getMinSteps(n, memo)
                << std::endl;
    }

    return 0;
}