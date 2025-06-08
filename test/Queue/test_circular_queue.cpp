#include <iostream>
#include "../../include/Queue/CircularQueue/CircularQueue.hpp"

using namespace std;
using namespace ds;

int main() {
    CircularQueue<int> queue(5);  // ũ�� 5�� ���� ť ����

    try {
        // ť�� ��� �߰�
        for (int i = 0; i < 4; i++) queue.enqueue(i + 10);  // 10, 11, 12, 13
        queue.printInfo();

        // �� �� ��� Ȯ�� �� ����
        cout << "peek: " << queue.peek() << '\n';   // 10
        cout << "dequeue: " << queue.dequeue() << '\n'; // 10

        queue.printInfo();

        // ��� �߰� �� ��ȯ Ȯ��
        queue.enqueue(99);
        queue.printInfo();

        // �� �� ���¿��� enqueue �õ�
        cout << "enqueue(100) �õ� ��..." << endl;
        queue.enqueue(100); // ���� �߻� ����
    } catch (const exception& e) {
        cerr << "���� �߻�: " << e.what() << '\n';
    }

    return 0;
}
