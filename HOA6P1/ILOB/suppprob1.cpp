#include <iostream>
#include "suppnode.h"

template <typename T>
int sequentialSearchArr(T data[], int maxSize, T dataFind)
{
    int i = 0;
    int comparisons = 0;

    while (i < maxSize)
    {
        comparisons++;

        if (dataFind == data[i])
        {
            return comparisons;
        }

        i++;
    }

    return comparisons;
}

template <typename T>
int sequentialSearchLL(Node<T> *node, T dataFind)
{
    int comparisons = 0;

    while (node != nullptr)
    {
        comparisons++;

        if (node->data == dataFind)
        {
            return comparisons;
        }

        node = node->next;
    }

    return comparisons;
}

int main()
{
    int data[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int maxSize = 10;

    std::cout << "Array: ";

    for (int i = 0; i < maxSize; i++)
    {
        std::cout << data[i] << " ";
    }

    std::cout << "\n\n";

    int arrayComparisons =
        sequentialSearchArr(data, maxSize, 18);

    std::cout << "Array Sequential Search\n";
    std::cout << "Comparisons needed to find 18: " << arrayComparisons << "\n\n";


    Node<int> *node1 = new_node(15);
    Node<int> *node2 = new_node(18);
    Node<int> *node3 = new_node(2);
    Node<int> *node4 = new_node(19);
    Node<int> *node5 = new_node(18);
    Node<int> *node6 = new_node(0);
    Node<int> *node7 = new_node(8);
    Node<int> *node8 = new_node(14);
    Node<int> *node9 = new_node(19);
    Node<int> *node10 = new_node(14);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;

    int linkedListComparisons =
        sequentialSearchLL(node1, 18);

    std::cout << "Linked List Sequential Search\n";
    std::cout << "Comparisons needed to find 18: " << linkedListComparisons << "\n";

    return 0;
}