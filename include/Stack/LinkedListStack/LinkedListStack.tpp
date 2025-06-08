#pragma once

namespace ds {

template <typename T>
Node<T>::Node(T value) {
    this->value = value;
    this->link = nullptr;
}

template <typename T>
LinkedListStack<T>::LinkedListStack() {
    this->top = nullptr;
    this->size = 0;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    std::cout << std::endl;
    while (!isEmpty()) {
        std::cout << "Deleting : " << pop() << '\n';
    }
}

template <typename T>
bool LinkedListStack<T>::isEmpty() {
    return this->top == nullptr;
}

template <typename T>
void LinkedListStack<T>::push(T data) {
    Node<T>* node = new Node<T>(data);
    node->link = this->top;
    this->top = node;
    size++;
}

template <typename T>
T LinkedListStack<T>::pop() {
    if (isEmpty()) throw std::runtime_error("Underflow Error");
    Node<T>* removed = this->top;
    this->top = removed->link;
    T ret = removed->value;
    delete removed;
    size--;
    return ret;
}

template <typename T>
T LinkedListStack<T>::peek() {
    if (isEmpty()) throw std::runtime_error("Underflow Error");
    return this->top->value;
}

template <typename T>
void LinkedListStack<T>::printInfo() {
    if (isEmpty()) {
        std::cout << "Empty." << '\n';
        return;
    }
    std::cout << "stack size : " << size << '\n';
    std::cout << "stack : top - [ ";
    Node<T>* tmp = this->top;
    while (tmp != nullptr) {
        std::cout << tmp->value;
        tmp = tmp->link;
        if (tmp != nullptr) std::cout << " -> ";
    }
    std::cout << " ] - bottom" << '\n';
}

} // namespace ds
