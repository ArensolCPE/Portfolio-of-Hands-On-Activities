#include <iostream>
#include <algorithm>
#include "bottomupdp.h"
#include "memoization.h"
#include "path.h"

int main()
{
    
    int matrix[4][4] = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int M = 4, N = 4;
    int targetCost = 27;

    int memo[4][4][100];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k <= targetCost; k++)
            {
                memo[i][j][k] = -1;
            }
        }
    }

    std::cout << "Count the Number of Paths in a Matrix: " << std::endl;
    std::cout << "Target Cost: " << targetCost
            << " | Paths Found: " << countPaths(0, 0, M, N, targetCost, matrix, memo)
            << std::endl;

    return 0;
}