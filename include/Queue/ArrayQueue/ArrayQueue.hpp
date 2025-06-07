#pragma once
#include <iostream>

namespace ds {

template <typename T>
class ArrayQueue {
private:
    T* queue;
    size_t size;
    int front, rear;

public:
    explicit ArrayQueue(size_t size = 10);
    ~ArrayQueue();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const T& data);
    T dequeue();
    T peek() const;
    void printInfo() const;
};
} // namespace ds

#include "ArrayQueue.tpp"