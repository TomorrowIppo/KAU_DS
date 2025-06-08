#pragma once

namespace ds {

template <typename T>
Node<T>::Node(T val) : value(val), link(nullptr) {}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr) {}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    std::cout << '\n';
    while (head != nullptr) {
        Node<T>* removed = head;
        head = removed->link;
        std::cout << "Deleting : " << removed->value << '\n';
        delete removed;
    }
}

template <typename T>
bool SinglyLinkedList<T>::isEmpty() {
    return head == nullptr;
}

template <typename T>
void SinglyLinkedList<T>::Insert(Node<T>* before, Node<T>* node) {
    if (isEmpty() && before == nullptr) {
        head = node;
    } else {
        node->link = before->link;
        before->link = node;
    }
}

template <typename T>
void SinglyLinkedList<T>::Delete(Node<T>* before) {
    if (isEmpty() || before == nullptr || before->link == nullptr) return;

    Node<T>* removed = before->link;
    before->link = removed->link;
    delete removed;
}

template <typename T>
Node<T>* SinglyLinkedList<T>::Search(T value) {
    Node<T>* cur = head;
    while (cur != nullptr) {
        if (cur->value == value) return cur;
        cur = cur->link;
    }
    return nullptr;
}

template <typename T>
void SinglyLinkedList<T>::Update() {
    // 구현 선택 사항: 예를 들어 값 변경 등
}

template <typename T>
void SinglyLinkedList<T>::Print() {
    Node<T>* cur = head;
    std::cout << "[ ";
    while (cur != nullptr) {
        std::cout << cur->value;
        cur = cur->link;
        if (cur != nullptr) std::cout << " -> ";
    }
    std::cout << " ]\n";
}

} // namespace ds
