# Graph Implementation in C++

본 프로젝트는 C++로 구현된 그래프 추상화 인터페이스(`IGraph`)를 기반으로, 인접 리스트(`AdjList`) 및 인접 행렬(`AdjMatrix`) 방식의 그래프 자료구조를 제공합니다.

---

## 📦 프로젝트 구조

```
Graph/
├── IGraph.hpp  # 그래프 공통 인터페이스
└── AdjList
    ├── AdjList.hpp # 인접 리스트 방식 헤더
    └── AdjList.tpp # 인접 리스트 구현부
Graph/
└── AdjMatrix
    ├── AdjacencyMatrix.hpp # 인접 행렬 방식 헤더
    └── AdjacencyMatrix.tpp # 인접 행렬 구현부
test/
└── Graph
    ├── test_adjlist.hpp    # 인접 행렬 방식 헤더
    └── test.tpp    # 인접 행렬 구현부
docs/
└── Graph
    └── README.md   # 인접 행렬 구현부

```

---

## 🧩 구성 요소

### IGraph.hpp

그래프 인터페이스로, 다음 기능을 제공합니다:

- insertVertex(int v)
- insertEdge(int u, int v, int w)
- deleteVertex(int v)
- deleteEdge(int u, int v)
- getAdjacency(int v)
- getVertices()
- getWeight(int u, int v)
- isEmpty()
- setDirected(bool)
- isDirected()
- printGraph()

---