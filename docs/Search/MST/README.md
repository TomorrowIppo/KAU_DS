# 📚 GraphSearch - 최소 신장 트리(MST) 알고리즘 사용법 안내

GraphSearch 네임스페이스는 그래프 탐색 외에도 최소 신장 트리(MST)를 구하는 두 가지 대표적인 알고리즘을 제공합니다:
1. Kruskal 알고리즘
2. Prim 알고리즘

## 1. Kruskal (크루스칼) 알고리즘
- 함수명: kruskal(IGraph& g)
- 그래프의 모든 간선을 가중치 기준으로 정렬한 후, 
  가장 낮은 가중치의 간선부터 사이클이 생기지 않도록 선택하여 MST를 구성합니다.
- Union-Find(Disjoint Set)을 사용하여 두 정점이 같은 트리에 속하는지 판단합니다.
- 중복 간선을 방지하기 위해 (u < v) 조건으로 간선을 수집합니다.
- 선택된 간선과 MST의 총 가중치를 출력합니다.

## 2. Prim (프림) 알고리즘
- 함수명: prim(IGraph& g)
- 시작 정점에서부터 연결된 가장 짧은 간선을 선택하며 MST를 구성합니다.
- 내부적으로 우선순위 큐(PriorityQueue)를 사용하여 최소 가중치 간선을 효율적으로 선택합니다.
- 각 정점의 부모 정보(parent[])와 최소 가중치(key[])를 관리합니다.
- 선택된 간선과 MST의 총 가중치를 출력합니다.

※ 두 알고리즘 모두 IGraph 인터페이스를 기반으로 하며,
   getVertices(), getAdjacency(int v), getWeight(int u, int v) 메서드를 활용합니다.
