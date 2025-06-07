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

# DoublyLinkedList 사용법 및 구조

## 개요  
이중 연결 리스트(DoublyLinkedList)는 각 노드가 이전 노드와 다음 노드의 주소를 모두 가지고 있어 양방향 탐색이 가능한 자료구조입니다.

## 주요 기능  
- 노드 삽입 (특정 노드 뒤에 새로운 노드 삽입)  
- 노드 삭제 (특정 노드 제거)  
- 노드 탐색 (값을 기준으로 노드 찾기)  
- 리스트 출력 (양방향 연결 상태 표시)

## 사용법 예제  

```cpp
// 이중 연결 리스트 생성
DoublyLinkedList<char> *ls = new DoublyLinkedList<char>();

// A 노드 생성 후 리스트에 삽입
Node<char> *node1 = new Node<char>('A');
ls->Insert(nullptr, node1);

// A 노드 뒤에 B 노드 삽입
Node<char>* finder = ls->Search('A');
Node<char>* node2 = new Node<char>('B');
ls->Insert(finder, node2);

// A 노드 뒤에 C 노드 삽입
finder = ls->Search('A');
Node<char>* node3 = new Node<char>('C');
ls->Insert(finder, node3);

// B 노드 뒤에 D 노드 삽입
finder = ls->Search('B');
Node<char>* node4 = new Node<char>('D');
ls->Insert(finder, node4);

// C 노드 삭제
finder = ls->Search('C');
ls->Delete(finder);

// 리스트 출력
ls->Print();
```

출력 예시:
```
[ A <-> B <-> D ]
```


## 삭제 시 자동 메모리 해제  
소멸자에서 리스트의 모든 노드를 순차적으로 삭제하며, 각 노드의 값이 출력됩니다.

예시 출력:
```  
Deleting : A  
Deleting : B  
Deleting : D  
```

## 참고 사항  
- Insert 함수는 before 노드 뒤에 새 노드를 삽입합니다.  
- Delete 함수는 지정한 노드를 리스트에서 제거합니다.  
- 빈 리스트에 첫 노드를 삽입할 때는 before를 nullptr로 지정합니다.  
- 리스트의 메모리 관리는 소멸자가 담당합니다.
