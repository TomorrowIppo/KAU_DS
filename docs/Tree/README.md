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
