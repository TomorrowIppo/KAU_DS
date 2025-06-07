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