#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

const int maxSize = 100;
void displayArr(int arr[]);

int main() {
    int unsortedArr[maxSize];
    std::srand(std::time(0));
    
    for(int i = 0; i <maxSize; i++) {
        unsortedArr[i] = std::rand()%100; 
    }
    displayArr(unsortedArr);
    //std::cout<<"\n bubbleSort testing: \n";
    //bubbleSort(unsortedArr, maxSize);
    //displayArr(unsortedArr);

    //std::cout<<"\n selectionSort testing: \n";
    //selectionSort(unsortedArr, maxSize);
    //displayArr(unsortedArr);

    //std::cout<<"\n insertionSort testing: \n";
    //insertionSort(unsortedArr, maxSize);
    //displayArr(unsortedArr);

    //std::cout<<"\n insertionSort2 testing: \n";
    //insertionSort2(unsortedArr, maxSize);
    //displayArr(unsortedArr);
}

void displayArr(int arr[]) {
    for(int i = 0; i <maxSize; i++) {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}