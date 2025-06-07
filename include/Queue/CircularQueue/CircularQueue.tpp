#define ENDL '\n'

namespace ds {

template <typename T>
CircularQueue<T>::CircularQueue(size_t size) {
    this->size = size;
    this->front = 0;
    this->rear = 0;
    this->queue = new T[size];
}

template <typename T>
CircularQueue<T>::~CircularQueue() {
    delete[] queue;
}

template <typename T>
bool CircularQueue<T>::isEmpty() {
    return front == rear;
}

template <typename T>
bool CircularQueue<T>::isFull() {
    return front == (rear + 1) % size;
}

template <typename T>
void CircularQueue<T>::enqueue(T data) {
    if (isFull()) throw std::runtime_error("FULL");
    rear = (rear + 1) % size;
    queue[rear] = data;
}

template <typename T>
T CircularQueue<T>::dequeue() {
    if (isEmpty()) throw std::runtime_error("EMPTY");
    front = (front + 1) % size;
    return queue[front];
}

template <typename T>
T CircularQueue<T>::peek() {
    if (isEmpty()) throw std::runtime_error("EMPTY");
    return queue[(front + 1) % size];
}

template <typename T>
void CircularQueue<T>::printInfo() {
    if (isEmpty()) {
        std::cout << "Empty." << ENDL;
        return;
    }

    std::cout << "queue size : " << (rear - front + size) % size << ENDL;
    std::cout << "queue : front - [ ";

    int cur = front;
    while (cur != rear) {
        cur = (cur + 1) % size;
        std::cout << queue[cur];
        if (cur != rear) std::cout << " <- ";
    }

    std::cout << " ] - rear" << std::endl;
}

} // namespace ds