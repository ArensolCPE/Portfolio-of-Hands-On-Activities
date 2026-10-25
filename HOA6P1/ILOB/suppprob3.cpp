#include <iostream>

template <typename T>
void binarySearchArr(T dataFind, T data[], int maxSize)
{
    int low = 0;
    int up = maxSize - 1;
    int comparisons = 0;

    while (low <= up)
    {
        int middle = (low + up) / 2;

        comparisons++;

        std::cout << "Comparison " << comparisons << ": ";
        std::cout << "low = " << low << ", middle = " << middle << ", up = " << up << ", value = " << data[middle] << "\n";

        if (dataFind == data[middle])
        {
            std::cout << "The search was successful.\n";
            std::cout << "The key " << dataFind << " was found after " << comparisons << " comparisons.\n";
            return;
        }
        else if (dataFind > data[middle])
        {
            low = middle + 1;
        }
        else
        {
            up = middle - 1;
        }
    }

    std::cout << "The search was unsuccessful.\n";
}

int main()
{
    int dataset[] =
    {
        3, 5, 6, 8, 11,
        12, 14, 15, 17, 18
    };

    int maxSize = 10;

    std::cout << "Sorted List: ";

    for (int i = 0; i < maxSize; i++)
    {
        std::cout << dataset[i] << " ";
    }

    std::cout << "\n\n";

    std::cout << "Searching for: 8\n\n";

    binarySearchArr(8, dataset, maxSize);

    return 0;
}