#pragma once
#include <iostream>

namespace ds {

template <typename T>
class Node {
public:
    Node<T>* link;
    T value;

    Node(T value);
};

template <typename T>
class LinkedListQueue {
private:
    Node<T>* front;
    Node<T>* rear;
    size_t size;

public:
    LinkedListQueue();
    ~LinkedListQueue();

    bool isEmpty();
    void enqueue(T data);
    T dequeue();
    T peek();
    void printInfo();
};

} // namespace ds

#include "LinkedListQueue.tpp"