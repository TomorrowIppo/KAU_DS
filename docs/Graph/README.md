# 📚 ArrayTree 사용법 및 구조

## 개요
ArrayTree는 부모 노드 정보를 배열로 표현한 트리 구조입니다.
각 노드는 부모 인덱스를 통해 연결되어 있으며,
-1 값은 루트 노드를 나타냅니다.
이 구조는 트리의 각 노드가 자신의 부모를 알고 있는 방식으로,
간단한 배열 기반 트리 표현에 적합합니다.

## 주요 기능
- find_root(parent): 부모 배열에서 루트 노드(부모가 -1인 노드) 찾기
- printTree(node, parent, indent, is_last): 트리를 전위 순회로 출력하며
  트리 구조를 시각적으로 표시

## 사용법 예제
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int find_root(const vector<int>& parent);
void printTree(int node, const vector<int>& parent, string indent = "", bool is_last = true);

int main() {
    int n = 6;
    vector<int> parent = {1, 3, 3, -1, 1, 2};

    int root = find_root(parent);
    if(root == -1) {
        cerr << "Error : Root Node를 찾을 수 없습니다.\n";
        return 1;
    }

    printTree(root, parent);

    return 0;
}
```

## 출력 예시
```
Node 3
├── Node 1
│   ├── Node 0
│   └── Node 4
└── Node 2
    └── Node 5
```


# 📚 BinaryTree (ds::BinaryTree) 사용법

## 개요
`ds::BinaryTree` 클래스는 연결 리스트 방식으로 이진 트리를 구현한 C++ 템플릿 클래스입니다.  
노드 삽입, 삭제, 그리고 다양한 순회(preorder, inorder, postorder, levelorder)를 지원합니다.

... (중략: 위 내용 그대로 포함)

# 📚 AdjList (ds::AdjList) 사용법

## 개요
`ds::AdjList`는 인접 리스트 기반의 그래프 자료구조입니다.  
유향/무향 그래프를 지원하며 정점, 간선 삽입/삭제 및 탐색 기능을 제공합니다.

## 테스트 코드 예제

```cpp
#include <iostream>
#include "../../include/Graph/AdjList/AdjList.hpp"

using namespace ds;

int main() {
    // 정점 5개짜리 그래프 생성
    AdjList graph(true);

    // isEmpty 검사
    std::cout << "\n그래프가 비어있나요? " << (graph.isEmpty() ? "Yes" : "No") << "\n\n";

    // 간선 추가 (무방향 그래프)
    graph.insertEdge(1, 2, 1);
    graph.insertEdge(1, 3, 3);
    graph.insertEdge(2, 4, 9);
    graph.insertEdge(3, 5, 12);
    graph.insertEdge(5, 1, 37);

    std::cout << "그래프 상태 (초기):\n";
    graph.printGraph();

    // 간선 삭제
    graph.deleteEdge(1, 3);
    std::cout << "\n간선 (1->3) 삭제 후:\n";
    graph.printGraph();

    // 정점 삭제 (간선 제거만)
    graph.deleteVertex(2);
    std::cout << "\n정점 2 삭제 (간선 제거) 후:\n";
    graph.printGraph();

    // 정점 추가 (사실 insertVertex는 크기 조정용이므로 v=7 넣어봄)
    graph.insertEdge(7, 1, -15);
    std::cout << "\n정점 7 추가 및 (7, 1) 간선 생성 후:\n";
    graph.printGraph();

    // isEmpty 검사
    std::cout << "\n그래프가 비어있나요? " << (graph.isEmpty() ? "Yes" : "No") << "\n";

    // Vertices 검사
    auto all_v = graph.getVertices();
    std::cout << "\n정점들 : ";
    for(auto v : all_v) {
        std::cout << v << ' ';
    }
    std::cout << "\n";

    // Weight 검사
    std::cout << "\n간선 (7, 1)의 weight : " << graph.getWeight(7, 1) << "\n";

    return 0;
}

```

## 출력 예시
```
그래프가 비어있나요? Yes

그래프 상태 (초기):
[AdjList]
[1] -> (3, 3) -> (2, 1) -> NULL
[2] -> (4, 9) -> NULL
[3] -> (5, 12) -> NULL
[4] -> NULL
[5] -> (1, 37) -> NULL

간선 (1->3) 삭제 후:
[AdjList]
[1] -> (2, 1) -> NULL
[2] -> (4, 9) -> NULL
[3] -> (5, 12) -> NULL
[4] -> NULL
[5] -> (1, 37) -> NULL

정점 2 삭제 (간선 제거) 후:
[AdjList]
[1] -> NULL
[3] -> (5, 12) -> NULL
[4] -> NULL
[5] -> (1, 37) -> NULL

정점 7 추가 및 (7, 1) 간선 생성 후:
[AdjList]
[1] -> NULL
[3] -> (5, 12) -> NULL
[4] -> NULL
[5] -> (1, 37) -> NULL
[7] -> (1, -15) -> NULL

그래프가 비어있나요? No

정점들 : 1 3 4 5 7

간선 (7, 1)의 weight : -15
```