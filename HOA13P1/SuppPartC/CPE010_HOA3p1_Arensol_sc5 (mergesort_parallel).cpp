#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include "mergesort_parallel.h"

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
    const int N = 5000000;
    std::mt19937 rng(12345);
    std::uniform_int_distribution<int> dist(-1000000, 1000000);

    std::vector<int> original(N);
    for (int& x : original) x = dist(rng);

    std::cout << "Hardware threads: " << std::thread::hardware_concurrency() << "\n";
    std::cout << "Sorting " << N << " ints\n\n";

    std::vector<int> a = original, b = original, c = original;

    double tSeq    = timeIt([&] { mergeSort(a); });
    double tThread = timeIt([&] { mergeSortThread(b); });
    double tAsync  = timeIt([&] { mergeSortAsync(c); });

    std::cout << "Sequential : " << tSeq    << " ms, sorted = " << std::is_sorted(a.begin(), a.end()) << "\n";
    std::cout << "std::thread: " << tThread << " ms, sorted = " << std::is_sorted(b.begin(), b.end()) << "\n";
    std::cout << "std::async : " << tAsync  << " ms, sorted = " << std::is_sorted(c.begin(), c.end()) << "\n";
    std::cout << "All results equal: " << (a == b && b == c) << "\n";

    return 0;
}