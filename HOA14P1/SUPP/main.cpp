#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "linear.h"
#include "binary.h"

void runTimeSpeed(int size) {
    std::vector<int> data(size);
    for(int i = 0; i < size; ++i) {
        data[i] = i; // Fixed: Fill sequentially so the array is sorted
    }

    int worstCaseTarget = -1;
    long repetitions = 100; //Repeat to accumulate measurable time

    //Measure Binary Search
    auto start_bin = std::chrono::high_resolution_clock::now();
    for(long r = 0; r < repetitions; ++r) {
        binarySearch(data, worstCaseTarget);
    }
    auto end_bin = std::chrono::high_resolution_clock::now();
    auto duration_bin = std::chrono::duration_cast<std::chrono::microseconds>(end_bin - start_bin);

    //Measure Linear Search
    auto start_lin = std::chrono::high_resolution_clock::now();
    for(long r = 0; r < repetitions; ++r) {
        linearSearch(data, worstCaseTarget);
    }
    auto end_lin = std::chrono::high_resolution_clock::now();
    auto duration_lin = std::chrono::duration_cast<std::chrono::microseconds>(end_lin - start_lin);

    std::cout << "Input Size: " << size << "\n";
    std::cout << "Binary Search: " << duration_bin.count() << " Microseconds\n";
    std::cout << "Linear Search: " << duration_lin.count() << " Microseconds\n";
    std::cout << "========================================\n";
}

int main(){
    std::cout << "Worst Case Time Complexities of Linear Search and Binary Search\n";
    std::cout << "========================================\n";
    
    std::vector<int> sampleSizes = {1000, 10000, 100000};

    for (int size : sampleSizes) {
        runTimeSpeed(size);
    }

    return 0;
}