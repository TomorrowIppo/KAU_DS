#include <iostream>
#include "../../include/Queue/LinkedListQueue/LinkedListQueue.hpp"

#define ENDL '\n'
using namespace std;
using namespace ds;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedListQueue<char>* queue = new LinkedListQueue<char>();

    queue->enqueue('A');
    queue->enqueue('B');
    queue->enqueue('C');
    queue->enqueue('D');

    cout << queue->dequeue() << ENDL;   // A
    cout << queue->peek() << ENDL;      // B

    queue->printInfo();
    delete queue;

    return 0;
}
