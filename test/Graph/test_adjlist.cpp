#include <iostream>
#include "../../include/Graph/AdjList/AdjList.hpp"

using namespace ds;

int main() {
    // ���� 5��¥�� �׷��� ����
    AdjList graph(true);

    // isEmpty �˻�
    std::cout << "\n�׷����� ����ֳ���? " << (graph.isEmpty() ? "Yes" : "No") << "\n\n";

    // ���� �߰� (������ �׷���)
    graph.insertEdge(1, 2, 1);
    graph.insertEdge(1, 3, 3);
    graph.insertEdge(2, 4, 9);
    graph.insertEdge(3, 5, 12);
    graph.insertEdge(5, 1, 37);

    std::cout << "�׷��� ���� (�ʱ�):\n";
    graph.printGraph();

    // ���� ����
    graph.deleteEdge(1, 3);
    std::cout << "\n���� (1->3) ���� ��:\n";
    graph.printGraph();

    // ���� ���� (���� ���Ÿ�)
    graph.deleteVertex(2);
    std::cout << "\n���� 2 ���� (���� ����) ��:\n";
    graph.printGraph();

    // ���� �߰� (��� insertVertex�� ũ�� �������̹Ƿ� v=7 �־)
    graph.insertEdge(7, 1, -15);
    std::cout << "\n���� 7 �߰� �� (7, 1) ���� ���� ��:\n";
    graph.printGraph();

    // isEmpty �˻�
    std::cout << "\n�׷����� ����ֳ���? " << (graph.isEmpty() ? "Yes" : "No") << "\n";

    // Vertices �˻�
    auto all_v = graph.getVertices();
    std::cout << "\n������ : ";
    for(auto v : all_v) {
        std::cout << v << ' ';
    }
    std::cout << "\n";

    // Weight �˻�
    std::cout << "\n���� (7, 1)�� weight : " << graph.getWeight(7, 1) << "\n";

    return 0;
}
