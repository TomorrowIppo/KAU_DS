#include "../../include/Tree/AVL/AVLTree.hpp"
#include <string>

using namespace ds;

int main() {
    AVLTree<std::string> avl;

    avl.insert(30, "A");
    avl.insert(20, "B");
    avl.insert(10, "C"); // LL 회전 발생

    avl.insert(40, "D");
    avl.insert(50, "E"); // RR 회전 발생

    avl.insert(25, "F"); // LR 회전 발생
    avl.insert(5, "G"); // RL 회전 발생

    avl.printInfo();

    avl.remove(40); // 삭제 및 균형 유지
    avl.remove(10);

    avl.printInfo();

    return 0;
}
