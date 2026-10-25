#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>
#include "merge_sort.h"
#include "mergesort_parallel.h"

template <typename T>
void printVector(const std::string& label, const std::vector<T>& v)
{
    std::cout << label << ": ";
    for (const T& x : v) std::cout << x << " ";
    std::cout << "\n";
}

template <typename F>
double timeIt(F&& f)
{
    auto start = std::chrono::steady_clock::now();
    f();
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}
 
int main()
{
    // Test 1: general unsorted integers
    std::vector<int> a = {38, 27, 43, 3, 9, 82, 10};
    printVector("Before", a);
    mergeSort(a);
    printVector("After ", a);
    std::cout << "\n";
 
    // Test 2: duplicates and negatives
    std::vector<int> b = {5, -2, 9, 5, 0, -2, 7};
    printVector("Before", b);
    mergeSort(b);
    printVector("After ", b);
    std::cout << "\n";

    return 0;
}