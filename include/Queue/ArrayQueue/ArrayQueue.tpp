#pragma once

namespace ds {

template <typename T>
ArrayQueue<T>::ArrayQueue(size_t size) 
    : size(size), front(-1), rear(-1)
{
    queue = new T[size];
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() 
{
    delete[] queue;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const
{
    return front == rear;
}

template <typename T>
bool ArrayQueue<T>::isFull() const
{
    return rear == static_cast<int>(size) - 1;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& data)
{
    if (isFull()) throw std::runtime_error("Queue is full");
    queue[++rear] = data;
}

template <typename T>
T ArrayQueue<T>::dequeue()
{
    if (isEmpty()) throw std::runtime_error("Queue is empty");
    return queue[++front];
}

template <typename T>
T ArrayQueue<T>::peek() const
{
    if (isEmpty()) throw std::runtime_error("Queue is empty");
    return queue[front + 1];
}

template <typename T>
void ArrayQueue<T>::printInfo() const
{
    if (isEmpty()) { 
        std::cout << "Empty." << '\n';
        return;
    }

    std::cout << "queue size : " << rear - front << '\n';
    std::cout << "queue : front - [ ";

    int cur = front;
    while (cur != rear) {
        std::cout << queue[++cur];
        if (cur != rear) std::cout << " <- ";
    }
    std::cout << " ] - rear" << std::endl;
}

} // namespace ds
