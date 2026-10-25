#ifndef LINEAR_H
#define LINEAR_H

#include <vector>

int linearSearch(const std::vector<int>&arr, int target) {
    for(size_t i = 0; i < arr.size(); ++i) {
        if(arr[i] == target) return static_cast<int>(i);
    }
    return -1;
}

#endif