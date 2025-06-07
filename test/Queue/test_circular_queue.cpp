#include <iostream>
#include "../../include/Queue/CircularQueue/CircularQueue.hpp"

using namespace std;
using namespace ds;

int main() {
    CircularQueue<int> queue(5);  // 크기 5인 원형 큐 생성

    try {
        // 큐에 요소 추가
        for (int i = 0; i < 4; i++) queue.enqueue(i + 10);  // 10, 11, 12, 13
        queue.printInfo();

        // 맨 앞 요소 확인 및 제거
        cout << "peek: " << queue.peek() << '\n';   // 10
        cout << "dequeue: " << queue.dequeue() << '\n'; // 10

        queue.printInfo();

        // 요소 추가 및 순환 확인
        queue.enqueue(99);
        queue.printInfo();

        // 꽉 찬 상태에서 enqueue 시도
        cout << "enqueue(100) 시도 중..." << endl;
        queue.enqueue(100); // 예외 발생 예상
    } catch (const exception& e) {
        cerr << "예외 발생: " << e.what() << '\n';
    }

    return 0;
}
