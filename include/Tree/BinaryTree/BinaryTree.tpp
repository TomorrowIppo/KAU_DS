#pragma once

namespace ds {

template <typename T>
Node<T>::Node(T id) {
    this->id = id;
    this->left = nullptr;
    this->right = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree() {
    this->root = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    destroy(this->root);
}

template <typename T>
bool BinaryTree<T>::isEmpty() {
    return root == nullptr;
}

template <typename T>
void BinaryTree<T>::destroy(Node<T>* node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

template <typename T>
void BinaryTree<T>::Insert(T parent, T child, int dir) {
    if (this->root == nullptr) this->root = new Node<T>(parent);

    Node<T>* c_node = new Node<T>(child);
    Node<T>* p_node = Search(parent);
    if (p_node == nullptr)
        throw std::invalid_argument("Insert failed: parent node not found.");

    if (dir == LEFT)
        p_node->left = c_node;
    else if (dir == RIGHT)
        p_node->right = c_node;
    else
        throw std::invalid_argument("Insert failed: direction must be 0 (left) or 1 (right).");
}

template <typename T>
void BinaryTree<T>::Delete(T id) {
    Node<T>* target = Search(id);
    if (target == nullptr)
        throw std::invalid_argument("Node not found.");

    if (target->left != nullptr || target->right != nullptr)
        throw std::logic_error("Only leaf node can be deleted.");

    Node<T>* parent = Search(id, true);

    if (parent == nullptr) {
        // target is root
        delete this->root;
        this->root = nullptr;
    }
    else {
        if (parent->left == target)
            parent->left = nullptr;
        else if (parent->right == target)
            parent->right = nullptr;

        delete target;
    }

    std::cout << "Node " << target->id << " deleted.\n";
}

template <typename T>
void BinaryTree<T>::printInfo(Node<T>* node, std::string indent, bool is_last, int dir) {
    if (dir != LEFT && dir != RIGHT && dir != ROOT)
        throw std::invalid_argument("Direction must be 0 (left), 1 (right) or -1 (root).");

    if (node == nullptr) node = this->root;

    std::cout << indent << (is_last ? "戌式式 " : "戍式式 ");
    if (dir == LEFT)
        std::cout << "(L)";
    else if (dir == RIGHT)
        std::cout << "(R)";
    std::cout << "Node " << node->id << '\n';

    std::queue<std::pair<Node<T>*, int>> children;
    if (node->left) children.push({ node->left, LEFT });
    if (node->right) children.push({ node->right, RIGHT });

    while (!children.empty()) {
        auto cur = children.front(); children.pop();
        printInfo(cur.first, indent + (is_last ? "    " : "弛   "), children.empty(), cur.second);
    }
}

template <typename T>
void BinaryTree<T>::preorder(Node<T>* node) {
    node = (node ? node : root);
    if (node == nullptr) return;

    std::cout << node->id << " ";
    if (node->left) preorder(node->left);
    if (node->right) preorder(node->right);
}

template <typename T>
void BinaryTree<T>::inorder(Node<T>* node) {
    node = (node ? node : root);
    if (node == nullptr) return;

    if (node->left) inorder(node->left);
    std::cout << node->id << " ";
    if (node->right) inorder(node->right);
}

template <typename T>
void BinaryTree<T>::postorder(Node<T>* node) {
    node = (node ? node : root);
    if (node == nullptr) return;

    if (node->left) postorder(node->left);
    if (node->right) postorder(node->right);
    std::cout << node->id << " ";
}

template <typename T>
void BinaryTree<T>::levelorder(Node<T>* node) {
    node = (node ? node : root);
    if (node == nullptr) return;

    std::queue<Node<T>*> q;
    q.push(node);
    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        if (cur) {
            std::cout << cur->id << " ";
            q.push(cur->left);
            q.push(cur->right);
        }
    }
}

template <typename T>
Node<T>* BinaryTree<T>::Search(T id, bool find_parent) {
    if (root == nullptr) return nullptr;
    std::stack<Node<T>*> s;
    s.push(this->root);

    while (!s.empty()) {
        auto cur = s.top(); s.pop();

        if (!find_parent && cur->id == id) return cur;

        if (find_parent) {
            if (cur->left && cur->left->id == id) return cur;
            if (cur->right && cur->right->id == id) return cur;
        }

        if (cur->left) s.push(cur->left);
        if (cur->right) s.push(cur->right);
    }
    return nullptr;
}

} // namespace ds
