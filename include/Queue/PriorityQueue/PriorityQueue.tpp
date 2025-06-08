#pragma once

using namespace std;

namespace ds {

// Node Implementation
template <typename T>
Node<T>::Node() {
    this->key = 0;
    this->value = T();
}

template <typename T>
Node<T>::Node(int key, T value) {
    this->key = key;
    this->value = value;
}

template <typename T>
int Node<T>::getKey() const {
    return this->key;
}

template <typename T>
T Node<T>::getValue() const {
    return this->value;
}

template <typename T>
void Node<T>::setKey(int key) {
    this->key = key;
}

template <typename T>
void Node<T>::setValue(T value) {
    this->value = value;
}

// PriorityQueue Implementation
template <typename T>
PriorityQueue<T>::PriorityQueue(HeapType type) {
    this->type = type;
    this->size = 0;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
bool PriorityQueue<T>::isFull() const {
    return size == MAX_ELEMENT - 1;
}

template <typename T>
int PriorityQueue<T>::getParentIndex(int idx) const {
    return idx / 2;
}

template <typename T>
int PriorityQueue<T>::getLeftIndex(int idx) const {
    return idx * 2;
}

template <typename T>
int PriorityQueue<T>::getRightIndex(int idx) const {
    return idx * 2 + 1;
}

template <typename T>
bool PriorityQueue<T>::getCondition(int p_key, int c_key) const {
    return (this->type == HeapType::MAX) ? (p_key < c_key) : (p_key > c_key);
}

template <typename T>
void PriorityQueue<T>::Insert(int key, T value) {
    if (isFull())
        throw logic_error("Heap is Full.");

    int idx = ++this->size;

    while (idx != 1 && getCondition(this->node[getParentIndex(idx)].getKey(), key)) {
        this->node[idx] = this->node[getParentIndex(idx)];
        idx = getParentIndex(idx);
    }

    node[idx].setKey(key);
    node[idx].setValue(value);
}

template <typename T>
Node<T> PriorityQueue<T>::Delete() {
    if (isEmpty())
        throw logic_error("Heap is Empty.");

    Node<T> ret = this->node[1];
    this->node[1] = this->node[this->size--];

    int idx = 1;
    while (getLeftIndex(idx) <= this->size) {
        int largest_idx = idx;
        int left = getLeftIndex(idx);
        int right = getRightIndex(idx);

        if (left <= this->size && getCondition(node[largest_idx].getKey(), node[left].getKey()))
            largest_idx = left;
        if (right <= this->size && getCondition(node[largest_idx].getKey(), node[right].getKey()))
            largest_idx = right;

        if (largest_idx == idx) break;

        swap(this->node[idx], this->node[largest_idx]);
        idx = largest_idx;
    }

    return ret;
}

template <typename T>
Node<T> PriorityQueue<T>::Top() {
    if (isEmpty())
        throw logic_error("Heap is Empty.");
    return this->node[1];
}

template <typename T>
void PriorityQueue<T>::printRecursive(int idx, string indent, bool is_last) const {
    if (idx > size) return;

    cout << indent;
    if (idx != 1)
        cout << (is_last ? "戌式式 " : "戍式式 ");

    cout << CYAN << this->node[idx].getKey() << RESET << " : (" << this->node[idx].getValue() << ")\n";

    int left = getLeftIndex(idx);
    int right = getRightIndex(idx);

    bool has_left = (left <= this->size);
    bool has_right = (right <= this->size);

    if (has_left)
        printRecursive(left, indent + (is_last ? "    " : "弛   "), !has_right);
    if (has_right)
        printRecursive(right, indent + (is_last ? "    " : "弛   "), true);
}

template <typename T>
void PriorityQueue<T>::printInfo() const {
    if (isEmpty()) {
        cout << "Heap is Empty." << ENDL;
        return;
    }
    printRecursive();
}

} // namespace ds
