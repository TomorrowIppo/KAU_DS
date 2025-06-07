// include/LinkedList/DoublyLinkedList/DoublyLinkedList.hpp
#pragma once
#include <iostream>

namespace ds {

template <typename T>
class Node {
public:
    T value;
    Node<T>* prev;
    Node<T>* next;
    Node(T val);
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    bool isEmpty();
    void Insert(Node<T>* before, Node<T>* node);
    void Delete(Node<T>* node);
    Node<T>* Search(T value);    // 선택 구현
    void Update();               // 선택 구현
    void Print();
};

} // namespace ds

#include "DoublyLinkedList.tpp"
