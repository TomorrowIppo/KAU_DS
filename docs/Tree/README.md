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

</br></br>

# 📚 BinaryTree (ds::BinaryTree) 사용법

## 개요
`ds::BinaryTree` 클래스는 연결 리스트 방식으로 이진 트리를 구현한 C++ 템플릿 클래스입니다.  
노드 삽입, 삭제, 그리고 다양한 순회(preorder, inorder, postorder, levelorder)를 지원합니다.

---

## 파일 구성
- `BinaryTree.hpp` : 클래스 선언 및 인터페이스
- `BinaryTree.tpp` : 템플릿 함수 구현
- `test.cpp`       : 사용 예제 및 테스트 코드

---

## 주요 타입 및 상수
- `ds::Node<T>` : 이진 트리 노드 클래스 (id, left, right 포인터 포함)
- `ds::BinaryTree<T>` : 이진 트리 클래스
- 방향 상수
  - `ds::LEFT`  = 0 (왼쪽 자식)
  - `ds::RIGHT` = 1 (오른쪽 자식)
  - `ds::ROOT`  = -1 (루트 노드 표시용)

---

## BinaryTree 주요 메서드

### 생성자 / 소멸자
- `BinaryTree()` : 빈 트리 생성
- `~BinaryTree()` : 동적 할당 메모리 해제

### 트리 상태 확인
- `bool isEmpty()` : 트리가 비었으면 `true` 반환

### 노드 조작
- `void Insert(T parent, T child, int dir)`  
  `parent` 노드 아래 `dir` 방향(`ds::LEFT` 또는 `ds::RIGHT`)에 `child` 노드를 삽입  
  (루트가 비어있으면 `parent`가 루트가 됨)

- `void Delete(T id)`  
  `id`에 해당하는 노드를 삭제. 자식이 없고 리프 노드인 경우만 삭제 가능

### 트리 탐색 및 출력
- `Node<T>* Search(T id, bool find_parent = false)`  
  `id` 노드 또는 `id`의 부모 노드 탐색

- `void printInfo(Node<T>* node = nullptr, std::string indent = "", bool is_last = true, int dir = ds::ROOT)`  
  트리 구조를 트리 형태로 출력 (기본값 루트부터)

### 트리 순회
- `void preorder(Node<T>* node = nullptr)`  
- `void inorder(Node<T>* node = nullptr)`  
- `void postorder(Node<T>* node = nullptr)`  
- `void levelorder(Node<T>* node = nullptr)`  

각각 전위, 중위, 후위, 레벨 순서 순회 후 노드 id를 출력

---

## 사용 예제

```cpp
#include "BinaryTree.hpp"
#include <iostream>

int main() {
    ds::BinaryTree<char>* bt = new ds::BinaryTree<char>();
    bt->Insert('A', 'B', ds::LEFT); // Insert(Parent, Child, Direction)
    bt->Insert('A', 'C', ds::RIGHT);
    bt->Insert('B', 'D', ds::LEFT);
    bt->Insert('B', 'E', ds::RIGHT);
    bt->Insert('E', 'F', ds::RIGHT);

    std::cout << "[TreeInfo]\n";
    bt->printInfo();
    std::cout << std::endl;

    bt->Delete('F');

    std::cout << "preorder   : ";
    bt->preorder();
    std::cout << std::endl;

    std::cout << "inorder    : ";
    bt->inorder();
    std::cout << std::endl;

    std::cout << "postorder  : ";
    bt->postorder();
    std::cout << std::endl;

    std::cout << "levelorder : ";
    bt->levelorder();
    std::cout << std::endl;

    delete bt;

    return 0;
}
```

## 출력 예시
```
[TreeInfo]
└── Node A
    ├── (L)Node B
    │   ├── (L)Node D
    │   └── (R)Node E
    │       └── (R)Node F
    └── (R)Node C

Node F deleted.
preorder   : A B D E C
inorder    : D B E A C
postorder  : D E B C A
levelorder : A B C D E
```

</br></br>

# 📚 BST (ds::BST) 사용법

## 개요
`ds::BST` 클래스는 이진 탐색 트리(BST, Binary Search Tree)를 C++ 템플릿으로 구현한 자료구조입니다.  
노드를 키 기준으로 정렬하여, 삽입, 삭제, 탐색 연산에서 평균적으로 O(log n)의 시간복잡도를 가집니다.

---

## 파일 구성
- `BST.hpp` : 클래스 선언 및 인터페이스
- `BST.tpp` : 템플릿 함수 구현
- `Node.hpp` : 공용 Node 클래스 정의
- `main.cpp` : 사용 예제 및 테스트 코드

---

## 주요 타입
- `ds::Node<T>` : 노드 클래스 (key, value, left, right, parent 포함)
- `ds::BST<T>` : BST 본체 클래스, key를 기준으로 노드 삽입 및 삭제 수행

---

## BST 주요 메서드

### 생성자 / 소멸자
- `BST()` : 빈 BST 생성
- `~BST()` : 동적 메모리 해제

### 노드 삽입 / 삭제 / 탐색
- `void insert(int key, const T& value)`  
  key 기준으로 노드를 삽입. 중복 key는 허용하지 않음

- `void remove(int key)`  
  해당 key 값을 갖는 노드를 삭제. 리프, 자식 하나, 자식 둘 모두 처리

- `Node<T>* search(int key)`  
  key 값을 갖는 노드를 탐색하여 포인터 반환 (없으면 nullptr)

### 출력 및 순회
- `void inorder(Node<T>* node = nullptr)`  
  중위 순회로 트리 출력

- `void printInfo(Node<T>* node = nullptr, std::string indent = "", bool is_last = true)`  
  트리 구조를 보기 좋게 출력

---

## 사용 예제

```cpp
#include "BST.hpp"
#include <string>

int main() {
    ds::BST<std::string> tree;

    tree.insert(10, "Root");
    tree.insert(5, "Left");
    tree.insert(15, "Right");
    tree.insert(3, "Left.Left");
    tree.insert(7, "Left.Right");

    std::cout << "[Tree Info]" << std::endl;
    tree.printInfo();

    std::cout << "[Inorder]" << std::endl;
    tree.inorder();

    tree.remove(5); // 삭제 테스트

    return 0;
}
```
## 출력 예시
```
[Tree Info]
└── (10, Root)
    ├── L: (5, Left)
    │   ├── L: (3, Left.Left)
    │   └── R: (7, Left.Right)
    └── R: (15, Right)

[Inorder]
(3, Left.Left) (5, Left) (7, Left.Right) (10, Root) (15, Right)

== Remove Node: 5 ==
└── (10, Root)
    ├── L: (7, Left.Right)
    │   └── L: (3, Left.Left)
    └── R: (15, Right)
```