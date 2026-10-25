#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <vector>

void shellSort(std::vector<int>& arr) {
    int shellSortArr = arr.size();

    for (int gap = shellSortArr / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < shellSortArr; ++i) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;

            }
            arr[j] = temp;
        }
    }
}

#endif