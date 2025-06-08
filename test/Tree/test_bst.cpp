#include "../../include/Tree/BST/BST.hpp"
#include <string>

using namespace ds;

int main() {
    BST<std::string> tree;

    tree.insert(10, "A");
    tree.insert(5, "B");
    tree.insert(15, "C");
    tree.insert(3, "D");
    tree.insert(7, "E");
    tree.insert(12, "F");
    tree.insert(17, "G");

    std::cout << "\n== Initial Tree ==" << std::endl;
    tree.printInfo();

    std::cout << "\n== Inorder Traversal ==" << std::endl;
    tree.inorder();

    std::cout << "\n== Search ==" << std::endl;
    int search_key = 7;
    Node<std::string>* result = tree.search(search_key);
    if (result) {
        std::cout << "Found key " << search_key << ": " << result->get_value() << std::endl;
    } else {
        std::cout << "Key " << search_key << " not found." << std::endl;
    }

    std::cout << "\n== Remove Node: 5 ==" << std::endl;
    tree.remove(5);
    tree.printInfo();

    std::cout << "\n== Final Inorder ==" << std::endl;
    tree.inorder();

    return 0;
}
