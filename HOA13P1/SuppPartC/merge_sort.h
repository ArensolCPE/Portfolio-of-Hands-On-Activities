#ifndef MERGE_SORT
#define MERGE_SORT

#include <vector>
#include <cstddef>

template <typename T>
void merge(std::vector<T>& arr, int left, int mid, int right)
{
    // Step 1: sizes of the two halves
    int n1 = mid - left + 1;   // number of elements in left half
    int n2 = right - mid;      // number of elements in right half

    // Step 2: copy each half into a temporary buffer
    std::vector<T> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i]; // left half
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j]; // right half

    // Step 3: repeatedly take the smaller front element
    int i = 0;        // index into L4
    int j = 0;        // index into R
    int k = left;     // index into arr (where the next value is written)

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {       // <= keeps the sort stable
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Step 4: one side is exhausted; copy whatever remains of the other
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// ---------------------------------------------------------------
// mergeSort(): recursively splits arr[left .. right] in half,
// sorts each half, then merges them.
// ---------------------------------------------------------------
template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right)
{
    // Base case: 0 or 1 element is already sorted
    if (left >= right) return;

    // Midpoint (written this way to avoid integer overflow)
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);        // sort left half
    mergeSort(arr, mid + 1, right);   // sort right half
    merge(arr, left, mid, right);     // combine the two sorted halves
}

// Convenience overload: sort the whole vector
template <typename T>
void mergeSort(std::vector<T>& arr)
{
    if (!arr.empty())
        mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
}

#endif