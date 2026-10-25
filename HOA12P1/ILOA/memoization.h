#ifndef MEMOIZATION_H
#define MEMOIZATION_H
#include <iostream>

int getMinSteps (int n, int memo[])
{
    if (n == 1) return 0; // base case
    if(memo[n] != -1) return memo[n]; // we have solved it already :)
    int r = 1 + getMinSteps(n - 1, memo); // '-1' step . 'r' will contain the optimal answer finally
    if(n%2 == 0) r = std::min( r , 1 + getMinSteps(n / 2, memo) ) ; // '/2' step
    if(n%3 == 0) r = std::min( r , 1 + getMinSteps(n / 3, memo) ) ; // '/3' step
    memo[n] = r ; // save the result. If you forget this step, then its same as plain recursion.
    return r;
}


#endif