#include "../../include/Queue/PriorityQueue/PriorityQueue.hpp"

using namespace ds;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    PriorityQueue<string> pq(HeapType::MAX);

    pq.Insert(3, "apple");
    pq.Insert(5, "banana");
    pq.Insert(1, "cherry");
    pq.Insert(4, "date");
    pq.Insert(2, "fig");

    pq.printInfo();

    cout << "Top: " << pq.Top().getKey() << ", " << pq.Top().getValue() << ENDL;

    cout << "Deleting...\n";
    while (!pq.isEmpty()) {
        auto node = pq.Delete();
        cout << "Deleted Node: (" << node.getKey() << ", " << node.getValue() << ")" << ENDL;
    }

    return 0;
}
