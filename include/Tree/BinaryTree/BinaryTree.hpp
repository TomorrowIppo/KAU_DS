#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <string>

namespace ds {

constexpr int LEFT = 0;
constexpr int RIGHT = 1;
constexpr int ROOT = -1;

template <typename T>
class Node {
public:
    Node<T>* left;
    Node<T>* right;
    T id;

    Node(T id);
};

template <typename T>
class BinaryTree {
private:
    Node<T>* root;
    void destroy(Node<T>* node);
public:
    BinaryTree();
    ~BinaryTree();

    bool isEmpty();
    void Insert(T parent, T child, int dir);
    void Delete(T id);

    void printInfo(Node<T>* node = nullptr, std::string indent = "", bool is_last = true, int dir = ROOT);
    void preorder(Node<T>* node = nullptr);
    void inorder(Node<T>* node = nullptr);
    void postorder(Node<T>* node = nullptr);
    void levelorder(Node<T>* node = nullptr);
    Node<T>* Search(T id, bool find_parent = false);
};

} // namespace ds

#include "BinaryTree.tpp"
