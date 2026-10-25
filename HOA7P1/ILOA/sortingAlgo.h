#ifndef SORTINGALGO_H
#define SORTINGALGO_H

template <typename T>
void selectionSort(T arr[], int maxSize)
{
    int POS;

    for (int i = 0; i < maxSize; i++)
    {
        POS = i;

        for (int j = i + 1; j < maxSize; j++)
        {
            if (arr[j] < arr[POS])
            {
                POS = j;
            }
        }

        std::swap(arr[i], arr[POS]);
    }
}

#endif