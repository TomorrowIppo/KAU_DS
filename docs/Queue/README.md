# 📚 ArrayQueue 사용법 및 구조

## 개요
ArrayQueue는 배열 기반으로 구현된 선입선출(FIFO) 큐 자료구조입니다.  
템플릿 클래스로 구현되어 있어 다양한 타입을 저장할 수 있으며,  
고정된 크기의 메모리 공간에서 동작합니다.

## 주요 기능
- enqueue(data): 큐에 요소 추가 (rear 증가)
- dequeue(): 큐에서 front 다음 요소 제거 및 반환
- peek(): front 다음 요소 반환하지만 제거하지 않음
- isEmpty(): 큐가 비어있는지 확인
- isFull(): 큐가 가득 찼는지 확인
- printInfo(): 현재 큐 상태 출력

## 사용법 예제
```cpp
#include "ArrayQueue.hpp"
using namespace ds;

int main() {
    ArrayQueue<int> queue(5);

    for (int i = 0; i < 5; i++) queue.enqueue(i + 3);
    std::cout << queue.peek() << std::endl;
    std::cout << queue.dequeue() << std::endl;

    queue.printInfo();
    return 0;
}
```

## 출력 예시
```
3
3
queue size : 4
queue : front - [ 4 <- 5 <- 6 <- 7 ] - rear
```

</br></br>

# 📚 LinkedListQueue 사용법 및 구조

## 개요
LinkedListQueue는 연결 리스트 기반으로 구현된 선입선출(FIFO) 큐 자료구조입니다.
템플릿 클래스로 구현되어 있어 다양한 타입을 저장할 수 있으며,
동적으로 메모리를 할당하므로 크기 제한이 없습니다.

## 주요 기능
- enqueue(data): 큐에 요소 추가 (rear 뒤에 연결)
- dequeue(): front 요소 제거 및 반환
- peek(): front 요소 반환하지만 제거하지 않음
- isEmpty(): 큐가 비어있는지 확인
- printInfo(): 현재 큐 상태 출력

## 사용법 예제
```cpp
#include "LinkedListQueue.hpp"
using namespace std;
using namespace ds;

int main() {
    LinkedListQueue<char> queue;

    queue.enqueue('A');
    queue.enqueue('B');
    queue.enqueue('C');
    queue.enqueue('D');

    cout << queue.dequeue() << endl;  // A
    cout << queue.peek() << endl;     // B

    queue.printInfo();
    return 0;
}
```

## 출력 예시
```
A
B
queue size : 3
queue : front - [ C <- D <- B ] - rear
```

</br></br>

# 📚 CircularQueue 사용법 및 구조

## 개요
CircularQueue는 배열 기반으로 구현된 원형 선입선출(FIFO) 큐입니다.
템플릿 클래스로 구현되어 있어 다양한 타입을 저장할 수 있으며,
고정된 크기의 메모리 공간에서 동작하며 공간 활용이 효율적입니다.

## 주요 기능
- enqueue(data): 큐에 요소 추가 (rear 증가, 순환)
- dequeue(): front 다음 요소 제거 및 반환
- peek(): front 다음 요소 반환하지만 제거하지 않음
- isEmpty(): 큐가 비어있는지 확인
- isFull(): 큐가 가득 찼는지 확인
- printInfo(): 현재 큐 상태 출력

## 사용법 예제
```cpp
#include "CircularQueue.hpp"
using namespace std;
using namespace ds;

int main() {
    CircularQueue<int> queue(5);

    for (int i = 0; i < 4; i++) queue.enqueue(i + 3);
    cout << queue.peek() << endl;     // 3
    cout << queue.dequeue() << endl;  // 3

    queue.printInfo();
    return 0;
}
```

## 출력 예시
```
3
3
queue size : 3
queue : front - [ 4 <- 5 <- 6 ] - rear
```

</br></br>

# 📚 PriorityQueue (힙 기반 우선순위 큐) 사용법 및 구조

## 개요
PriorityQueue는 배열 기반의 힙 자료구조를 사용하여 구현했습니다.
최대 힙과 최소 힙을 토글을 통해 지원하며, 템플릿 클래스로 다양한 데이터 타입에 대응할 수 있습니다.
고정 크기 배열로 구현되어 있어 빠른 삽입과 삭제가 가능하고, 힙 구조를 트리 형태로 콘솔에 출력할 수 있습니다.

## 주요 기능
- Insert(key, value): 우선순위 키를 기준으로 힙 조건을 유지하며 요소 삽입
- Delete(): 루트 노드를 삭제하고 힙 재구성 (최우선 요소 제거)
- Top(): 현재 우선순위가 가장 높은 루트 노드 조회
- isEmpty(): 큐가 비어있는지 확인
- isFull(): 큐가 가득 찼는지 확인
- printInfo(): 힙 구조를 트리 형태로 콘솔에 출력

## 사용법 예제
```cpp
#include "PriorityQueue.hpp"
#include <iostream>

using namespace std;
using namespace ds;

int main() {
    PriorityQueue<string> pq(HeapType::MAX);

    pq.Insert(3, "apple");
    pq.Insert(5, "banana");
    pq.Insert(1, "cherry");
    pq.Insert(4, "date");
    pq.Insert(2, "fig");

    pq.printInfo();

    cout << "Top: " << pq.Top().getKey() << ", " << pq.Top().getValue() << endl;

    cout << "Deleting...\n";
    while (!pq.isEmpty()) {
        auto node = pq.Delete();
        cout << "Deleted Node: (" << node.getKey() << ", " << node.getValue() << ")" << endl;
    }

    return 0;
}
```

## 출력 예시
```
5 : (banana)
    ├── 4 : (date)
    │   ├── 3 : (apple)
    │   └── 2 : (fig)
    └── 1 : (cherry)
Top: 5, banana
Deleting...
Deleted Node: (5, banana)
Deleted Node: (4, date)
Deleted Node: (3, apple)
Deleted Node: (2, fig)
Deleted Node: (1, cherry)
```
