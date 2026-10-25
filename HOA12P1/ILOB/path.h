#ifndef PATH_H
#define PATH_H
#include <iostream>
#include <algorithm>

int countPaths(int r, int c, int M, int N, int targetCost, int matrix[4][4], int memo[4][4][100])
{
    if (r == M - 1 && c == N - 1) 
    {
        if (targetCost == matrix[r][c]) 
        {
            return 1; // base case: exact cost matched at destination
        }
        else 
        {
            return 0; // base case: destination reached but cost doesn't match
        }
    }

    if (r >= M || c >= N || targetCost < 0) return 0;
    if (memo[r][c][targetCost] != -1) return memo[r][c][targetCost]; // we have solved it already :)
    
    int nextCost = targetCost - matrix[r][c];
    int r_paths = countPaths(r + 1, c, M, N, nextCost, matrix, memo) + countPaths(r, c + 1, M, N, nextCost, matrix, memo); // will contain the optimal answer finally
    
    memo[r][c][targetCost] = r_paths; // save the result. If not, then its same as plain recursion.
    return r_paths;
}

#endif