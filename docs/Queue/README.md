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
