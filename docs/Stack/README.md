# 📚 ArrayStack 사용법 및 구조

## 개요
ArrayStack은 배열 기반으로 구현된 후입선출(LIFO) 스택 자료구조입니다.
템플릿 클래스로 구현되어 있어 다양한 타입을 저장할 수 있으며, 
고정된 크기의 메모리 공간에서 동작합니다.

## 주요 기능
- push(data): 스택에 요소 추가 (top 증가)
- pop(): 스택에서 top 요소 제거 및 반환
- peek(): top 요소를 반환하지만 제거하지 않음
- isEmpty(): 스택이 비어있는지 확인
- isFull(): 스택이 가득 찼는지 확인
- printInfo(): 현재 스택 상태 출력

## 사용법 예제
```cpp
#include "ArrayStack.hpp"
using namespace ds;

int main() {
    ArrayStack<char> stack;

    stack.push('A');
    stack.push('B');
    stack.push('C');
    stack.pop(); // C 제거
    stack.peek(); // B 반환
    stack.push('D');
    stack.printInfo();
    return 0;
}
```

## 출력 예시
```
A
C
B
top pos : 2
stack : top - [ D -> B -> A ]
```
<br/> <br/> 

# 📚 LinkedListStack 사용법 및 구조

## 개요
LinkedListStack은 연결리스트 기반으로 구현된 스택 자료구조입니다.
각 노드는 데이터를 보관하고 다음 노드를 가리키는 링크 포인터를 포함합니다.
LIFO(Last-In First-Out) 방식으로 동작하며, 크기 제한이 없습니다.

## 주요 기능
- push(data): 스택에 요소 추가 (top 앞에 삽입)
- pop(): top 요소 제거 및 반환
- peek(): top 요소 반환 (제거하지 않음)
- isEmpty(): 스택이 비어있는지 확인
- printInfo(): 현재 스택 상태 출력
- 소멸자에서 메모리 자동 해제 및 삭제 로그 출력

## 사용법 예제
```cpp
#include "LinkedListStack.hpp"

using namespace ds;

int main() {
    LinkedListStack<char> stack;

    stack.push('A');
    stack.push('B');
    stack.push('C');
    stack.pop(); // C 제거
    stack.peek(); // B 반환
    stack.push('D');
    stack.printInfo();
}
```

## 출력 예시
```
A
C
B
stack size : 3
stack : top - [ D -> B -> A ] - bottom

Deleting : D
Deleting : B
Deleting : A
```
