# 📚 Dijkstra 알고리즘 사용법 안내

GraphSearch 네임스페이스는 최단 경로 탐색을 위한 Dijkstra 알고리즘을 제공합니다.

## Dijkstra (다익스트라) 알고리즘
- 함수명: dijkstra(IGraph& g, int start)
- 주어진 시작 정점(start)에서 다른 모든 정점까지의 최단 경로 거리를 계산합니다.
- 최소 우선순위 큐(PriorityQueue)를 활용하여 가장 가까운 정점을 우선적으로 방문합니다.
- 방문한 정점은 visited[] 배열로 관리하며, dist[] 배열에 최단 거리를 기록합니다.
- getAdjacency(u)와 getWeight(u, v)를 통해 인접 정점 및 가중치를 조회합니다.

## 동작 원리 요약
- 시작 정점의 거리(dist[start])를 0으로 초기화하고 나머지는 무한대(INF)로 설정
- 큐에서 최소 거리 정점을 꺼내어 인접 정점들의 거리를 갱신
- 모든 정점의 최단 거리를 출력 (도달 불가능한 정점은 "INF"로 표시)

※ 이 구현은 IGraph 인터페이스를 기반으로 하며,
   내부적으로 우선순위 큐(PriorityQueue) 자료구조를 사용합니다.
