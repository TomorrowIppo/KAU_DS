#include <iostream>
#include "../../include/Queue/ArrayQueue/ArrayQueue.hpp"

using namespace ds;

int main() {

    int size = 5;
    ArrayQueue<int> queue(size);

    for (int i = 0; i < size; i++) queue.enqueue(i + 3);

    std::cout << queue.peek() << '\n';
    std::cout << queue.dequeue() << '\n';

    queue.printInfo();

    return 0;
}
