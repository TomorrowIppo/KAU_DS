#pragma once
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define ENDL    '\n'

constexpr int MAX_ELEMENT = 200;

enum class HeapType {
    MAX,
    MIN
};

namespace ds {

template <typename T>
class Node {
private:
    int key;
    T value;

public:
    Node();
    Node(int key, T value);
    int getKey() const;
    T getValue() const;
    void setKey(int key);
    void setValue(T value);
};

template <typename T>
class PriorityQueue {
private:
    Node<T> node[MAX_ELEMENT];
    int size;
    HeapType type;

    void printRecursive(int idx = 1, std::string indent = "", bool is_last = true) const;
    int getParentIndex(int idx) const;
    int getLeftIndex(int idx) const;
    int getRightIndex(int idx) const;
    bool getCondition(int p_key, int c_key) const;

public:
    PriorityQueue(HeapType type);
    ~PriorityQueue();
    void Insert(int key, T value);
    Node<T> Delete();
    Node<T> Top();
    bool isEmpty() const;
    bool isFull() const;
    void printInfo() const;
};

} // namespace ds

#include "PriorityQueue.tpp"
