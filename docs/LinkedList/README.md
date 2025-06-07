# 📚 SinglyLinkedList 사용법 및 구조

## 개요
SinglyLinkedList는 단일 연결 리스트(단방향 연결 리스트) 자료구조를 템플릿 클래스로 구현한 것입니다.  
각 노드는 데이터와 다음 노드를 가리키는 포인터를 가지며, 리스트의 처음을 가리키는 `head` 포인터로 관리됩니다.

---

## 주요 기능

- **Insert(before, node)**: 특정 노드 `before` 뒤에 새로운 노드 `node` 삽입  
- **Delete(before)**: 특정 노드 `before` 뒤의 노드를 삭제  
- **Search(value)**: 값이 `value`인 노드를 탐색하여 반환  
- **Print()**: 리스트 전체 내용을 출력  
- **isEmpty()**: 리스트가 비어있는지 여부 반환  

---

## 동작 예시

```cpp
SinglyLinkedList<char> ls;

// A 노드 삽입 (맨 앞)
Node<char>* nodeA = new Node<char>('A');
ls.Insert(nullptr, nodeA);

// A 노드 뒤에 B 삽입
Node<char>* nodeB = new Node<char>('B');
ls.Insert(ls.Search('A'), nodeB);

// A 노드 뒤에 C 삽입 (B보다 앞에 삽입)
Node<char>* nodeC = new Node<char>('C');
ls.Insert(ls.Search('A'), nodeC);

// B 노드 뒤에 D 삽입
Node<char>* nodeD = new Node<char>('D');
ls.Insert(ls.Search('B'), nodeD);

// C 노드 뒤의 노드(B) 삭제
ls.Delete(ls.Search('C'));

// 리스트 출력
ls.Print();
```
## 실행 결과

```
[ A -> C -> D ]
Deleting : A
Deleting : C
Deleting : D
```