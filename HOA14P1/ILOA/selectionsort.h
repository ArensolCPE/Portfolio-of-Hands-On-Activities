#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <vector>
#include <algorithm>

void selectionSort(std::vector<int>& arr) {
    int selectionArr = arr.size();

    for (int i = 0; i < selectionArr - 1; ++i) {
        int selectionArrMin_index =  i;

        for (int j = i + 1; j < selectionArr; ++j) {
            if (arr[j] < arr[selectionArrMin_index]) {
                selectionArrMin_index = j;
            }
        }
        std::swap (arr[i], arr[selectionArrMin_index]);
    }
}

#endif