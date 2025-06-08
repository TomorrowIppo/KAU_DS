#define ENDL '\n'

namespace ds {

template <typename T>
Node<T>::Node(T value) {
    this->value = value;
    this->link = nullptr;
}

template <typename T>
LinkedListQueue<T>::LinkedListQueue() {
    this->size = 0;
    this->front = nullptr;
    this->rear = nullptr;
}

template <typename T>
LinkedListQueue<T>::~LinkedListQueue() {
    while (!isEmpty()) {
        std::cout << "Deleting : " << dequeue() << ENDL;
    }
}

template <typename T>
bool LinkedListQueue<T>::isEmpty() {
    return (front == nullptr) && (rear == nullptr);
}

template <typename T>
void LinkedListQueue<T>::enqueue(T data) {
    Node<T>* node = new Node<T>(data);

    if (isEmpty()) {
        front = rear = node;
    } else {
        rear->link = node;
        rear = node;
    }

    size++;
}

template <typename T>
T LinkedListQueue<T>::dequeue() {
    if (isEmpty()) throw std::runtime_error("EMPTY");

    Node<T>* removed = front;
    T ret = removed->value;

    if (size == 1) {
        front = rear = nullptr;
    } else {
        front = removed->link;
    }

    size--;
    delete removed;
    return ret;
}

template <typename T>
T LinkedListQueue<T>::peek() {
    if (isEmpty()) throw std::runtime_error("EMPTY");
    return front->value;
}

template <typename T>
void LinkedListQueue<T>::printInfo() {
    if (isEmpty()) {
        std::cout << "Empty." << ENDL;
        return;
    }

    std::cout << "queue size : " << size << ENDL;
    std::cout << "queue : front - [ ";

    Node<T>* cur = front;
    while (cur != nullptr) {
        std::cout << cur->value;
        cur = cur->link;
        if (cur != nullptr) std::cout << " <- ";
    }

    std::cout << " ] - rear" << std::endl;
}

} // namespace ds
