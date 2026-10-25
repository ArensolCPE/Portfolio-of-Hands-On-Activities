#include <iostream>

template <typename T>
int recursiveBinarySearch(
    T data[],
    int low,
    int up,
    T dataFind,
    int &comparisons)
{
    if (low > up)
    {
        return -1;
    }

    int middle = (low + up) / 2;

    comparisons++;

    std::cout << "Comparison " << comparisons << ": ";
    std::cout << "low = " << low << ", middle = " << middle << ", up = " << up << ", value = " << data[middle] << "\n";

    if (dataFind == data[middle])
    {
        return middle;
    }
    else if (dataFind > data[middle])
    {
        return recursiveBinarySearch(
            data,
            middle + 1,
            up,
            dataFind,
            comparisons
        );
    }
    else
    {
        return recursiveBinarySearch(
            data,
            low,
            middle - 1,
            dataFind,
            comparisons
        );
    }
}

int main()
{
    int dataset[] =
    {
        3, 5, 6, 8, 11,
        12, 14, 15, 17, 18
    };

    int maxSize = 10;
    int comparisons = 0;

    std::cout << "Sorted List: ";

    for (int i = 0; i < maxSize; i++)
    {
        std::cout << dataset[i] << " ";
    }

    std::cout << "\n\n";

    std::cout << "Searching for: 8\n\n";

    int result = recursiveBinarySearch(
        dataset,
        0,
        maxSize - 1,
        8,
        comparisons
    );

    if (result != -1)
    {
        std::cout << "\nThe search was successful.\n";
        std::cout << "The key 8 was found at index " << result << ".\n";
        std::cout << "The key 8 was found after " << comparisons << " comparisons.\n";
    } 
    else
    {
        std::cout << "\nThe search was unsuccessful.\n";
    }

    return 0;
}