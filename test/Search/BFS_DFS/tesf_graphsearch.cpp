#include "../../../include/Graph/AdjList/AdjList.hpp"
#include "../../../include/Graph/AdjMatrix/AdjMatrix.hpp"
#include "../../../include/Search/BFS_DFS/GraphSearch.hpp"

using namespace ds;

int main() {
    // 인접행렬 탐색

    AdjMatrix g(5);

    g.insertEdge(1, 2, 15);
    g.insertEdge(1, 4, 20);
    g.insertEdge(2, 3, -9);
    g.insertEdge(2, 5, 1);
    g.insertEdge(4, 5, 3); 
    g.insertEdge(3, 1, 0); // 순환 발생

    // 그래프 형태 출력
    g.printGraph();

    std::cout << "DFS:\n";
    GraphSearch::dfs(g, 1);

    std::cout << "BFS:\n";
    GraphSearch::bfs(g, 1);

    std::cout << "\n-------------------------------------------------------------------------------\n\n";

    // 인접리스트 탐색
    AdjList h;

    h.insertEdge(1, 2, 15);
    h.insertEdge(1, 4, 20);
    h.insertEdge(2, 3, -9);
    h.insertEdge(2, 5, 1);
    h.insertEdge(4, 5, 3); 
    h.insertEdge(3, 1, 0); // 순환 발생

    // 그래프 형태 출력
    h.printGraph();

    std::cout << "DFS:\n";
    GraphSearch::dfs(h, 1);

    std::cout << "BFS:\n";
    GraphSearch::bfs(h, 1);
}