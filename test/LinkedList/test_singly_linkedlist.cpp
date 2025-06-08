// test/LinkedList/test_singly_linkedlist.cpp
#include "../../include/LinkedList/SinglyLinkedList/SinglyLinkedList.hpp"
using namespace ds;

int main() {
    SinglyLinkedList<char>* ls = new SinglyLinkedList<char>();

    auto node1 = new Node<char>('A');
    ls->Insert(nullptr, node1);

    auto finder = ls->Search('A');
    auto node2 = new Node<char>('B');
    ls->Insert(finder, node2);

    finder = ls->Search('A');
    auto node3 = new Node<char>('C');
    ls->Insert(finder, node3);

    finder = ls->Search('B');
    auto node4 = new Node<char>('D');
    ls->Insert(finder, node4);

    finder = ls->Search('C');
    ls->Delete(finder);

    ls->Print();
    delete ls;
}
