#ifndef MERGESORT_PARALLEL_H
#define MERGESORT_PARALLEL_H

#include <vector>
#include <thread>
#include <future>
#include <functional>
#include "merge_sort.h"

// ---------------------------------------------------------------
// Version 1: std::thread
// Spawn a thread for the left half, sort the right half on the
// current thread, then join() before merging.
// depth limits how many levels may spawn threads (2^depth leaves),
// so we don't create thousands of threads for tiny sub-arrays.
// ---------------------------------------------------------------
template <typename T>
void mergeSortThread(std::vector<T>& arr, int left, int right, int depth)
{
    if (left >= right) return;
    int mid = left + (right - left) / 2;

    if (depth > 0) {
        std::thread t([&arr, left, mid, depth]() {
            mergeSortThread(arr, left, mid, depth - 1);
        });
        mergeSortThread(arr, mid + 1, right, depth - 1);
        t.join();                       // MUST join (or detach) before t is destroyed
    } else {
        mergeSort(arr, left, mid);      // sequential from here down
        mergeSort(arr, mid + 1, right);
    }
    merge(arr, left, mid, right);       // safe: both halves are finished
}

// ---------------------------------------------------------------
// Version 2: std::async
// Same idea, but the task returns a std::future. get() waits for
// the result AND re-throws any exception the task threw.
// std::launch::async forces a real new thread; without it the
// implementation may run the task lazily on get().
// ---------------------------------------------------------------
template <typename T>
void mergeSortAsync(std::vector<T>& arr, int left, int right, int depth)
{
    if (left >= right) return;
    int mid = left + (right - left) / 2;

    if (depth > 0) {
        std::future<void> fut = std::async(std::launch::async,
            [&arr, left, mid, depth]() {
                mergeSortAsync(arr, left, mid, depth - 1);
            });
        mergeSortAsync(arr, mid + 1, right, depth - 1);
        fut.get();                      // wait + propagate exceptions
    } else {
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
    }
    merge(arr, left, mid, right);
}

// Convenience wrappers (depth 3 -> up to 8 leaf tasks)
template <typename T>
void mergeSortThread(std::vector<T>& arr, int depth = 3)
{
    if (!arr.empty()) mergeSortThread(arr, 0, static_cast<int>(arr.size()) - 1, depth);
}

template <typename T>
void mergeSortAsync(std::vector<T>& arr, int depth = 3)
{
    if (!arr.empty()) mergeSortAsync(arr, 0, static_cast<int>(arr.size()) - 1, depth);
}

#endif