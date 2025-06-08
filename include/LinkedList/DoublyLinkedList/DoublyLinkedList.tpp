// include/LinkedList/DoublyLinkedList/DoublyLinkedList.tpp
#pragma once

namespace ds {

template <typename T>
Node<T>::Node(T val) : value(val), prev(nullptr), next(nullptr) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    std::cout << '\n';
    while (head != nullptr) {
        Node<T>* removed = head;
        head = removed->next;
        std::cout << "Deleting : " << removed->value << '\n';
        delete removed;
    }
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() {
    return head == nullptr;
}

template <typename T>
void DoublyLinkedList<T>::Insert(Node<T>* before, Node<T>* node) {
    if (isEmpty() && before == nullptr) {
        head = node;
    } else {
        Node<T>* next = before->next;
        node->prev = before;
        node->next = next;
        if (next != nullptr) next->prev = node;
        before->next = node;
    }
}

template <typename T>
void DoublyLinkedList<T>::Delete(Node<T>* node) {
    if (node == nullptr) return;

    Node<T>* prev = node->prev;
    Node<T>* next = node->next;

    if (prev != nullptr) prev->next = next;
    if (next != nullptr) next->prev = prev;

    if (node == head) head = next;

    delete node;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::Search(T value) {
    Node<T>* cur = head;
    while (cur != nullptr) {
        if (cur->value == value) return cur;
        cur = cur->next;
    }
    return nullptr;
}

template <typename T>
void DoublyLinkedList<T>::Update() {
    // 선택 구현
}

template <typename T>
void DoublyLinkedList<T>::Print() {
    std::cout << "[ ";
    Node<T>* cur = head;
    while (cur != nullptr) {
        std::cout << cur->value;
        cur = cur->next;
        if (cur != nullptr) std::cout << " <-> ";
    }
    std::cout << " ]\n";
}

} // namespace ds
