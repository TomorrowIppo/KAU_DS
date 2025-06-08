#pragma once
#include <iostream>

namespace ds {

template <typename T>
class CircularQueue {
private:
    T* queue;
    size_t size;
    int front, rear;

public:
    CircularQueue(size_t size = 10);
    ~CircularQueue();

    bool isEmpty();
    bool isFull();
    void enqueue(T data);
    T dequeue();
    T peek();
    void printInfo();
};

} // namespace ds

#include "CircularQueue.tpp"
