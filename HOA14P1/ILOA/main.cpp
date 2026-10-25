#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
#include "selectionsort.h"
#include "shellsort.h"

void runTimeSpeed(const std::string&testRun, const std::vector<int>& baseInput) {
    std::vector<int> vec_selectionSort = baseInput;
    std::vector<int> vec_shellSort = baseInput;

    auto run_sel = std::chrono::high_resolution_clock::now();
        selectionSort(vec_selectionSort);
    auto end_sel = std::chrono::high_resolution_clock::now();
    auto duration_sel = std::chrono::duration_cast<std::chrono::microseconds>(end_sel - run_sel);

    auto run_shell = std::chrono::high_resolution_clock::now();
        shellSort(vec_shellSort);
    auto end_shell = std::chrono::high_resolution_clock::now();
    auto duration_shell = std::chrono::duration_cast<std::chrono::microseconds>(end_shell - run_shell);

    std::cout << "=====================================================================\n";
    std::cout << "Input Condition: " << testRun << "\n";
    std::cout << "Selection Sort: " << duration_sel.count() << "Microseconds\n";
    std::cout << "Shell Sort: " << duration_shell.count() << "Microseconds\n";

}

int main() {
    const int size = 100;
    std::cout << "The Best Case & Worst Case Complexity of Shell Sort & Selection Sort\n";
    std::vector<int> bestCase;
    for(int i = 1; i <= size; ++i) {
        bestCase.push_back(i);
    }

    runTimeSpeed ("Best Case Complexity", bestCase);

    std::vector<int> worstCase;
    for(int i = size; i >= 1; --i){
        worstCase.push_back(i);
    }

    runTimeSpeed("Worst Case Complexity", worstCase);
    std::cout << "=====================================================================\n";
    
    return 0;
}
