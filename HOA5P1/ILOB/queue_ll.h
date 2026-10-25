#ifndef QUEUE_LL_H
#define QUEUE_LL_H
#include <iostream>

template <typename T>
class qNode {
public:
    T data;
    qNode* next;
};

template <typename T>
qNode<T>* createNode(T newData) {
    qNode<T>* newNode = new qNode<T>();
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
bool isEmpty(qNode<T>* frontPtr) {
    return (frontPtr == nullptr);
}

template <typename T>
void emQueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr) {
    qNode<T>* newNode = createNode(newData);


    if((*frontPtr)== nullptr && (*backPtr)== nullptr) {
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }

    //point the back next to the new node
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
    return;
}

template <typename T>
T deQueue(qNode<T>** frontPtr, qNode<T>** backPtr) {
    //creating a temporary pointer
    if((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        std::cout << "Queue is empty, nothing to dequeue" << std::endl;
        return T();
    }
    qNode<T>* temp = nullptr;
    temp = (*frontPtr);
    T data = temp->data;

    //check if the queue has only one node left
    if((*frontPtr) == (*backPtr)) {
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete temp;
        return data;
    } 

    //update the front pointer
    (*frontPtr) = (*frontPtr)->next;

    //point the temp next to null
    temp->next = nullptr;
    delete temp;
    return data;
}

//display all the elements in the queue
template <typename T>
void displayALL(qNode<T>* frontPtr) {
    //catch if the queue is empty
    if(frontPtr == nullptr) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    //temporary pointer to store the front pointer
    qNode<T>* temp = frontPtr;
    std::cout << "Queue elements: ";
    //loop through the queue and print the temporary pointer data
    while(temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

}


#endif