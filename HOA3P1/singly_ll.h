#ifndef SINGLY_LL_H
#define SINGLY_LL_H

template <typename T>
class SinglyList{
public:
    T data;
    SinglyList<T>* next = nullptr;
};

//Traversal
template <typename T>
void ListTraversal(SinglyList<T>* head){

    if (head == nullptr){
        std::cout << "The list is empty\n";
        return;
    }

    while(head != nullptr){
        std::cout << head->data;

        if(head->next != nullptr){
            std::cout << " -> ";
        }

        head = head->next;
    }

    std::cout << std::endl;
}

//Insert at head
template <typename T>
void sllInsertHead(T newData, SinglyList<T>** head){

    SinglyList<T>* newNode = new SinglyList<T>;
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

//Insert after a node
template <typename T>
void sllGeneralInsert(T newData, SinglyList<T>* prevNode){

    if(prevNode == nullptr){
        std::cout << "Previous node cannot be null\n";
        return;
    }

    SinglyList<T>* newNode = new SinglyList<T>;
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

//Insert at end
template <typename T>
void sllInsertEnd(T newData, SinglyList<T>** head){

    SinglyList<T>* newNode = new SinglyList<T>;
    newNode->data = newData;
    newNode->next = nullptr;

    // FIX: handle empty list
    if(*head == nullptr){
        *head = newNode;
        return;
    }

    SinglyList<T>* currentNode = *head;

    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

//Delete node
template <typename T>
void sllDeleteNode(T findData, SinglyList<T>** head){

    if (*head == nullptr) return;

    SinglyList<T>* currNode = *head;
    SinglyList<T>* prevNode = nullptr;

    while (currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }

    if(currNode == nullptr){
        std::cout << "Data not found\n";
        return;
    }

    if(prevNode == nullptr){
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    delete currNode;
}

//Delete entire list
template <typename T>
void sllDeleteList(SinglyList<T>** head){

    SinglyList<T>* current = *head;

    while(current != nullptr){
        SinglyList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}

#endif