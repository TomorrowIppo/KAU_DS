#pragma once
#include <iostream>

namespace ds {

template <typename T>
class ArrayStack {
private:
    T* stack;
    int top;
    size_t size;

public:
    ArrayStack(size_t size = 100);
    ~ArrayStack();

    bool isEmpty() const;
    bool isFull() const;

    void push(T data);
    T pop();
    T peek() const;
    void printInfo() const;
};

} // namespace ds

#include "ArrayStack.tpp"
