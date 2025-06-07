#pragma once

#include <iostream>

namespace ds {

template <typename T>
class Node {
public:
    T value;
    Node<T>* link;
    Node(T value);
};

template <typename T>
class LinkedListStack {
private:
    Node<T>* top;
    size_t size;
public:
    LinkedListStack();
    ~LinkedListStack();
    bool isEmpty();
    void push(T data);
    T pop();
    T peek();
    void printInfo();
};

} // namespace ds

#include "LinkedListStack.tpp"
