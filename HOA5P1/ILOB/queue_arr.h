#ifndef QUEUE_ARR_H
#define QUEUE_ARR_H
#include <iostream>

template <typename T>
class queueArr {
    private:
        T* q_arr;
        size_t q_capacity;
        size_t q_size;
        int q_front;
        int q_back;

    public:
    //constructor
        queueArr(size_t capacity);

        bool Empty();
        size_t Size();
        void Clear();

        T Front();
        T Back();
        void emQueue(T newData);
        void deQueue();

        //copy constructor
        queueArr(const queueArr<T>& other);

        //copy assignment operator
        queueArr<T>& operator=(const queueArr<T>& other);

        //destructor
        ~queueArr();

};

//constructor
template <typename T>
queueArr<T>::queueArr(size_t capacity) {
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_arr = new T[q_capacity];
}

//copy constructor
template <typename T>
queueArr<T>::queueArr(const queueArr<T>& other) {
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_arr = new T[q_capacity];
    for (size_t i = 0; i < q_capacity; ++i) {
        q_arr[i] = other.q_arr[i];
    }
}

//copy assignment operator
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr<T>& other) {
    if (this == &other) {
        return *this;
    }
//destructor
    delete[] q_arr;
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_arr = new T[q_capacity];
    for (size_t i = 0; i < q_capacity; ++i) {
        q_arr[i] = other.q_arr[i];
    }
    return *this;
}

template <typename T>
bool queueArr<T>::Empty() {
    return (q_size == 0);
}

template <typename T>
size_t queueArr<T>::Size() {
    return q_size;
}

template <typename T>
void queueArr<T>::Clear() {
    q_size = 0;
    q_front = 0;
    q_back = -1;
}
//front() function
template <typename T>
T queueArr<T>::Front() {
    if(Empty()) {
        std::cout << "Queue is empty, no front element" << std::endl;
        return T();
    }
    return q_arr[q_front];
}
//back() function
template <typename T>
T queueArr<T>::Back() {
    if(Empty()) {
        std::cout << "Queue is empty, no back element" << std::endl;
        return T();
    }
    return q_arr[q_back];
}
//emQueue() function
template <typename T>
void queueArr<T>::emQueue(T newData) {
    //check if the queue is full
    if(q_size == q_capacity) {
        std::cout << "Queue is full\n" << std::endl;
        return;
    }
    //compute the q_back index in a circular manner
    q_back = (q_back + 1) % q_capacity;

    //assign the q_array with the updated q_back to the value
    q_arr[q_back] = std::move(newData);
    //increment the size of the queue
    q_size++;
}

//deQueue() function
template <typename T>
void queueArr<T>::deQueue() {
    //check if the queue is empty
    if(Empty()) {
        std::cout << "Queue is empty\n" << std::endl;
        return;
    }
    //compute the q_front index in a circular manner
    q_front = (q_front + 1) % q_capacity;
    //decrement the size of the queue
    q_size--;
    //reset index if the queue is empty
    if(Empty()) {
        Clear();
        return;
    }
}

template <typename T>
queueArr<T>::~queueArr() {
    delete[] q_arr;
}

#endif