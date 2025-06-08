# 📚 GraphSearch 사용법 안내

GraphSearch 네임스페이스는 IGraph 인터페이스 기반의 그래프 탐색 알고리즘을 제공합니다.
주요 기능으로 DFS(깊이 우선 탐색)와 BFS(너비 우선 탐색)를 지원합니다.

## 1. DFS (Depth-First Search)
- 함수명: dfs(const IGraph& g, int start)
- 내부적으로 dfsUtil 함수를 재귀적으로 호출하여 깊이 우선 탐색을 수행합니다.
- 방문한 정점은 std::unordered_set<int>를 사용해 중복 방문을 방지합니다.
- 방문 순서대로 정점을 출력합니다.

## 2. BFS (Breadth-First Search)
- 함수명: bfs(const IGraph& g, int start)
- std::queue를 이용하여 너비 우선 탐색을 수행합니다.
- 시작 정점부터 인접한 정점을 먼저 탐색하며,
  방문 여부는 std::unordered_set<int>를 사용해 관리합니다.
- 방문 순서대로 정점을 출력합니다.

※ 이 기능들은 IGraph 인터페이스에서 제공하는 getAdjacency(int v) 함수를 통해
   인접 정점을 조회하는 방식으로 구현됩니다.
