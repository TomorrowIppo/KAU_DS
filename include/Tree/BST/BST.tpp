#pragma once
#include <queue>
#include <stdexcept>

namespace ds {

// Constructor & Destructor
template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::~BST() {
    clear(root);
}

// Insert
template <typename T>
void BST<T>::insert(int key, const T& value) {
    Node<T>* node = new Node<T>(key, value);
    root = recursive_insert(root, node);
    if (root) root->set_parent(nullptr);
}

template <typename T>
Node<T>* BST<T>::recursive_insert(Node<T>* cur, Node<T>* node) {
    if (!cur) return node;

    if (node->get_key() < cur->get_key()) {
        Node<T>* left = recursive_insert(cur->get_left(), node);
        cur->set_left(left);
        if (left) left->set_parent(cur);
    } else {
        Node<T>* right = recursive_insert(cur->get_right(), node);
        cur->set_right(right);
        if (right) right->set_parent(cur);
    }

    return cur;
}

// Search
template <typename T>
Node<T>* BST<T>::search(int key) const {
    Node<T>* cur = root;
    while (cur) {
        int cur_key = cur->get_key();
        if (key == cur_key) return cur;
        cur = (key < cur_key) ? cur->get_left() : cur->get_right();
    }
    return nullptr;
}

// Remove
template <typename T>
void BST<T>::remove(int key) {
    root = remove_node(root, key);
    if (root) root->set_parent(nullptr);
}

template <typename T>
Node<T>* BST<T>::remove_node(Node<T>* cur, int key) {
    if (!cur) return nullptr;

    if (key < cur->get_key()) {
        cur->set_left(remove_node(cur->get_left(), key));
    } else if (key > cur->get_key()) {
        cur->set_right(remove_node(cur->get_right(), key));
    } else {
        if (!cur->get_left() && !cur->get_right()) {
            delete cur;
            return nullptr;
        }
        if (!cur->get_left()) {
            Node<T>* temp = cur->get_right();
            temp->set_parent(cur->get_parent());
            delete cur;
            return temp;
        }
        if (!cur->get_right()) {
            Node<T>* temp = cur->get_left();
            temp->set_parent(cur->get_parent());
            delete cur;
            return temp;
        }
        Node<T>* successor = find_min(cur->get_right());
        cur->set_key(successor->get_key());
        cur->set_value(successor->get_value());
        cur->set_right(remove_node(cur->get_right(), successor->get_key()));
    }
    return cur;
}

// Utilities
template <typename T>
Node<T>* BST<T>::find_min(Node<T>* node) const {
    while (node->get_left()) node = node->get_left();
    return node;
}

template <typename T>
void BST<T>::clear(Node<T>* node) {
    if (!node) return;
    clear(node->get_left());
    clear(node->get_right());
    std::cout << "(" << node->get_key() << ", " << node->get_value() << ") deleted" << std::endl;
    delete node;
}

template <typename T>
void BST<T>::inorder() const {
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "[Inorder]" << std::endl;
    inorder_helper(this->root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::inorder_helper(Node<T>* node) const {
    if (!node) return;
    inorder_helper(node->get_left());
    std::cout << "(" << node->get_key() << ", " << node->get_value() << ") ";
    inorder_helper(node->get_right());
}

template <typename T>
void BST<T>::printInfo() const {
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "[BST Info]" << std::endl;
    printInfo_helper();
}

template <typename T>
void BST<T>::printInfo_helper(Node<T>* node, std::string indent, bool is_last, Direction dir) const {
    using namespace treevis;
    using namespace std;

    if (dir != Direction::LEFT && dir != Direction::RIGHT && dir != Direction::ROOT)
        throw invalid_argument("Invalid direction for printInfo");

    if (!node) node = this->root;

    cout << indent << (is_last ? "������ " : "������ ");
    if (dir == Direction::LEFT)  cout << YELLOW << "L" << RESET << ": ";
    if (dir == Direction::RIGHT) cout << GREEN << "R" << RESET << ": ";

    cout << "(" << CYAN << node->get_key() << RESET << ", " << node->get_value() << ")" << endl;

    queue<pair<Node<T>*, Direction>> children;
    if (node->get_left())  children.push({node->get_left(), Direction::LEFT});
    if (node->get_right()) children.push({node->get_right(), Direction::RIGHT});

    while (!children.empty()) {
        auto child = children.front(); children.pop();
        printInfo_helper(child.first, indent + (is_last ? "    " : "��   "), children.empty(), child.second);
    }
}

template <typename T>
Node<T>* BST<T>::get_root() const {
    return this->root;
}

} // namespace ds
