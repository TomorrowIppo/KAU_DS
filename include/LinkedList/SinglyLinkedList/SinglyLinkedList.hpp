// include/LinkedList/SinglyLinkedList/SinglyLinkedList.hpp
#pragma once
#include <iostream>

namespace ds {

template <typename T>
class Node {
public:
    T value;
    Node<T>* link;
    Node(T val);
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    bool isEmpty();
    void Insert(Node<T>* before, Node<T>* node);
    void Delete(Node<T>* before);
    Node<T>* Search(T value);    // 선택 구현
    void Update();               // 선택 구현
    void Print();
};

} // namespace ds

#include "SinglyLinkedList.tpp"
