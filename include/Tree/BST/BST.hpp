#pragma once
#include "Node.hpp"
#include <iostream>
#include <string>

namespace ds {

enum class Direction { LEFT, RIGHT, ROOT };

namespace treevis {
    constexpr auto RESET  = "\033[0m";
    constexpr auto CYAN   = "\033[36m";
    constexpr auto GREEN  = "\033[32m";
    constexpr auto YELLOW = "\033[33m";
}

template <typename T>
class BST {
protected:
    Node<T>* root;

public:
    BST();
    virtual ~BST();

    virtual void insert(int key, const T& value);
    virtual Node<T>* search(int key) const;
    virtual void remove(int key);
    virtual void printInfo() const;

    Node<T>* get_root() const;
    void inorder() const;

protected:
    Node<T>* find_min(Node<T>* node) const;
    virtual Node<T>* recursive_insert(Node<T>* cur, Node<T>* node);
    virtual Node<T>* remove_node(Node<T>* cur, int key);
    void clear(Node<T>* node);
    void inorder_helper(Node<T>* node) const;
    void printInfo_helper(Node<T>* node, std::string indent, bool is_last, Direction dir) const;
};

} // namespace ds

#include "BST.tpp"
