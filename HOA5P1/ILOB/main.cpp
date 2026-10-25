#include <iostream>
#include "queue_ll.h"
#include "queue_arr.h"

int main() {
    qNode<int>* front = nullptr;
    qNode<int>* back = nullptr;


    emQueue(1, &front, &back);
    std::cout << "Front: " << front->data << ", Back: " << back->data << std::endl;
    emQueue(2, &front, &back);
    emQueue(3, &front, &back);
    std::cout << "Front: " << front->data << ", Back: " << back->data << std::endl;

    //displayALL()
    displayALL(front);
    deQueue(&front, &back);
    std::cout << "Front: " << front->data << ", Back: " << back->data << std::endl;
    deQueue(&front, &back);
    std::cout << "Front: " << front->data << ", Back: " << back->data << std::endl;
    deQueue(&front, &back);
    deQueue(&front, &back);
    displayALL(front);

    //object creation for queueArr
    queueArr<int> q(6);
    q.emQueue(1);
    std::cout << "Front: " << q.Front() << ", Back: " << q.Back() << ", Size: " << q.Size() << std::endl;
    q.emQueue(2);
    std::cout << "Front: " << q.Front() << ", Back: " << q.Back() << ", Size: " << q.Size() << std::endl;
    q.emQueue(3);
    std::cout << "Front: " << q.Front() << ", Back: " << q.Back() << ", Size: " << q.Size() << std::endl;
    q.emQueue(4);
    std::cout << "Front: " << q.Front() << ", Back: " << q.Back() << ", Size: " << q.Size() << std::endl;
    q.emQueue(5);
    std::cout << "Front: " << q.Front() << ", Back: " << q.Back() << ", Size: " << q.Size() << std::endl;
    q.emQueue(6);
    std::cout << "Front: " << q.Front() << ", Back: " << q.Back() << ", Size: " << q.Size() << std::endl;
    q.emQueue(7);
    std::cout << "Front: " << q.Front() << ", Back: "<< q.Back() << ", Size: " << q.Size() << std::endl;
    
    return 0;
}