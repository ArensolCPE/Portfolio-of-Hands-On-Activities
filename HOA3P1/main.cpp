#include <iostream>
#include "singly_ll.h"

int main() {

    //create nodes:
    SinglyList<char>* head = nullptr;
    SinglyList<char>* second = nullptr;
    SinglyList<char>* third = nullptr;
    SinglyList<char>* fourth = nullptr;

    //allocates memory in the heap
    head = new SinglyList<char>;
    second = new SinglyList<char>;
    third = new SinglyList<char>;
    fourth = new SinglyList<char>;

    //storing a value inside the node
    head->data = 'J';
    second->data = 'H';
    third->data = 'A';
    fourth->data = 'I';

    //assign the next to the node
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    std::cout << "Testing the ListTraversal function:\n";
    ListTraversal(head);

    std::cout << "Testing insert at head:\n";
    sllInsertHead('Q', &head);
    ListTraversal(head);

    std::cout << "Testing insert at any location:\n";
    sllGeneralInsert('X', head->next->next);
    ListTraversal(head);

    std::cout << "Testing insert at end:\n";
    sllInsertEnd('U', &head);
    ListTraversal(head);

    std::cout << "Testing delete node:\n";
    sllDeleteNode('X', &head);
    ListTraversal(head);

    sllDeleteNode('Q', &head);
    ListTraversal(head);

    sllDeleteNode('U', &head);
    ListTraversal(head);

    std::cout << "Deleting the whole list:\n";
    sllDeleteList(&head);
    ListTraversal(head);

    return 0;
}