#include <iostream>
#include "../../include/Tree/BinaryTree/BinaryTree.hpp"

int main() {
    /*
    [최종 트리]
        A
       / \
      B   C
     / \
    D   E
         \
          F
    */
    ds::BinaryTree<char>* bt = new ds::BinaryTree<char>();
    bt->Insert('A', 'B', ds::LEFT); // Insert(Parent, Child, Direction)
    bt->Insert('A', 'C', ds::RIGHT);
    bt->Insert('B', 'D', ds::LEFT);
    bt->Insert('B', 'E', ds::RIGHT);
    bt->Insert('E', 'F', ds::RIGHT);

    std::cout << "[TreeInfo]\n";
    bt->printInfo();
    std::cout << std::endl;

    bt->Delete('F');

    std::cout << "preorder   : ";
    bt->preorder();
    std::cout << std::endl;

    std::cout << "inorder    : ";
    bt->inorder();
    std::cout << std::endl;

    std::cout << "postorder  : ";
    bt->postorder();
    std::cout << std::endl;

    std::cout << "levelorder : ";
    bt->levelorder();
    std::cout << std::endl;

    delete bt;

    return 0;
}
