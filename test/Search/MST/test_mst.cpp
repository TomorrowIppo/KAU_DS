#include <iostream>
#include "../../../include/Graph/AdjMatrix/AdjMatrix.hpp"
#include "../../../include/Graph/AdjList/AdjList.hpp"
#include "../../../include/Search/MST/Kruskal.hpp"
#include "../../../include/Search/MST/Prim.hpp"

using namespace ds;

int main() {
    AdjMatrix g(5);    // 무방향 그래프

    // 단방향이 기본이므로 양방향 간선을 직접 넣어줌
    g.insertEdge(1, 2, 1);
    g.insertEdge(1, 3, 2);
    g.insertEdge(2, 4, 11);
    g.insertEdge(3, 5, 5);
    g.insertEdge(5, 1, 7);

    g.printGraph();
    std::cout << "\n";
    GraphSearch::kruskal(g);
    GraphSearch::prim(g);

    return 0;
}