#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main()
{
    int voteArr[maxSize];

    int candidate1 = 0;
    int candidate2 = 0;
    int candidate3 = 0;
    int candidate4 = 0;
    int candidate5 = 0;

    std::srand(std::time(0));

    // Generator for 100 votes from 1 to 5
    for (int i = 0; i < maxSize; i++)
    {
        voteArr[i] = (std::rand() % 5) + 1;
    }

    std::cout << "Unsorted Array:\n";
    displayArr(voteArr);

    std::cout << "\nSelection Sort Testing:\n";
    selectionSort(voteArr, maxSize);
    displayArr(voteArr);

    // Headcount for the overall votes
    for (int i = 0; i < maxSize; i++)
    {
        if (voteArr[i] == 1)
        {
            candidate1++;
        }
        else if (voteArr[i] == 2)
        {
            candidate2++;
        }
        else if (voteArr[i] == 3)
        {
            candidate3++;
        }
        else if (voteArr[i] == 4)
        {
            candidate4++;
        }
        else if (voteArr[i] == 5)
        {
            candidate5++;
        }
    }

    std::cout << "\nVote Count:\n";

    std::cout << "Candidate 1 - Bo Dalton Capistrano: "
            << candidate1 << " votes\n";

    std::cout << "Candidate 2 - Cornelius Raymon Agustin: "
            << candidate2 << " votes\n";

    std::cout << "Candidate 3 - Deja Jayla Banaga: "
            << candidate3 << " votes\n";

    std::cout << "Candidate 4 - Lalla Brielle Yabut: "
            << candidate4 << " votes\n";

    std::cout << "Candidate 5 - Franklin Rolano Castro: "
            << candidate5 << " votes\n";


    // Find the candidate with the highest number of votes
    int highest = candidate1;
    int winner = 1;

    if (candidate2 > highest)
    {
        highest = candidate2;
        winner = 2;
    }

    if (candidate3 > highest)
    {
        highest = candidate3;
        winner = 3;
    }

    if (candidate4 > highest)
    {
        highest = candidate4;
        winner = 4;
    }

    if (candidate5 > highest)
    {
        highest = candidate5;
        winner = 5;
    }


    std::cout << "\nWinning Candidate:\n";

    if (winner == 1)
    {
        std::cout << "Bo Dalton Capistrano";
    }
    else if (winner == 2)
    {
        std::cout << "Cornelius Raymon Agustin";
    }
    else if (winner == 3)
    {
        std::cout << "Deja Jayla Bansaga";
    }
    else if (winner == 4)
    {
        std::cout << "Lalla Brielle Yabut";
    }
    else if (winner == 5)
    {
        std::cout << "Franklin Rolano Castro";
    }

    std::cout << " with " << highest << " votes.\n";

    return 0;
}

void displayArr(int arr[])
{
    for (int i = 0; i < maxSize; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
