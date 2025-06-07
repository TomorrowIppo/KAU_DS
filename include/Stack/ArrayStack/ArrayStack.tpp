#pragma once

namespace ds {

template <typename T>
ArrayStack<T>::ArrayStack(size_t size)
    : top(-1), size(size)
{
    stack = new T[size];
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    delete[] stack;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return top == -1;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return top == size - 1;
}

template <typename T>
void ArrayStack<T>::push(T data) {
    if (isFull()) throw std::runtime_error("Overflow Error");
    stack[++top] = data;
}

template <typename T>
T ArrayStack<T>::pop() {
    if (isEmpty()) throw std::runtime_error("Underflow Error");
    return stack[top--];
}

template <typename T>
T ArrayStack<T>::peek() const {
    if (isEmpty()) throw std::runtime_error("Underflow Error");
    return stack[top];
}

template <typename T>
void ArrayStack<T>::printInfo() const {
    if (isEmpty()) {
        std::cout << "Empty.\n";
        return;
    }

    std::cout << "top pos : " << top << '\n';
    std::cout << "stack : top - [ ";

    for (int i = top; i >= 0; --i) {
        std::cout << stack[i];
        if (i != 0) std::cout << " -> ";
    }

    std::cout << " ]\n";
}

} // namespace ds
