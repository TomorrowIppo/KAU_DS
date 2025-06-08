#include <iostream>
#include <stdexcept>
#include <iomanip>

namespace ds {

inline EdgeVertex::EdgeVertex(int to, int weight, EdgeVertex* next)
    : to(to), weight(weight), next(next) {}

inline AdjList::AdjList(bool dir) : dir(dir) {}

inline AdjList::~AdjList() {
    for (auto& item : this->table) {
        EdgeVertex* head = item.second;
        while (head) {
            EdgeVertex* temp = head;
            head = head->next;
            delete temp;
        }
    }
}

inline void AdjList::insertVertex(int v) {
    if (table.count(v)) return;
    table[v] = nullptr;
}

inline void AdjList::insertEdge(int u, int v, int w) {
    if (!this->table.count(u)) insertVertex(u);
    if (!this->table.count(v)) insertVertex(v);

    EdgeVertex* newNode = new EdgeVertex(v, w, this->table[u]);
    this->table[u] = newNode;

    if (!this->dir) {
        EdgeVertex* revNode = new EdgeVertex(u, w, this->table[v]);
        this->table[v] = revNode;
    }
}

inline void AdjList::setDirected(bool directed) {
    this->dir = directed;
}

inline bool AdjList::isDirected() const {
    return this->dir;
}

inline void AdjList::deleteEdge(int u, int v) {
    if (!this->table.count(u)) return;

    EdgeVertex* cur = this->table[u];
    EdgeVertex* prev = nullptr;

    while (cur) {
        if (cur->to == v) {
            if (prev) prev->next = cur->next;
            else this->table[u] = cur->next;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

inline void AdjList::deleteVertex(int v) {
    if (!this->table.count(v)) return;

    EdgeVertex* cur = this->table[v];
    while (cur) {
        EdgeVertex* next = cur->next;
        delete cur;
        cur = next;
    }
    this->table.erase(v);

    for (auto& item : this->table) {
        int key = item.first;
        EdgeVertex* cur = item.second;
        EdgeVertex* prev = nullptr;

        while (cur) {
            if (cur->to == v) {
                if (prev) prev->next = cur->next;
                else this->table[key] = cur->next;
                delete cur;
                break;
            }
            prev = cur;
            cur = cur->next;
        }
    }
}

inline std::vector<int> AdjList::getAdjacency(int v) const {
    if (!this->table.count(v))
        throw std::out_of_range("Vertex does not exist");

    std::vector<int> adj;
    EdgeVertex* cur = this->table.at(v);
    while (cur) {
        adj.push_back(cur->to);
        cur = cur->next;
    }
    return adj;
}

inline std::vector<int> AdjList::getVertices() const {
    std::vector<int> vertices;
    vertices.reserve(this->table.size());

    for (const auto& pair : this->table) {
        vertices.push_back(pair.first);
    }
    return vertices;
}

inline int AdjList::getWeight(int u, int v) const {
    if (!this->table.count(u))
        throw std::out_of_range("Vertex u does not exist");

    EdgeVertex* cur = this->table.at(u);
    while (cur != nullptr) {
        if (cur->to == v)
            return cur->weight;
        cur = cur->next;
    }

    throw std::out_of_range("Edge from u to v does not exist");
}

inline bool AdjList::isEmpty() const {
    return this->table.empty();
}

inline void AdjList::printGraph() const {
    constexpr const char* GREEN = "\033[32m";
    constexpr const char* BLUE = "\033[34m";
    constexpr const char* RESET = "\033[0m";

    if (this->table.empty()) {
        std::cout << "Graph is empty.\n";
        return;
    }

    std::cout << "[AdjList]\n";
    for (const auto& item : this->table) {
        int v = item.first;
        EdgeVertex* cur = item.second;

        std::cout << GREEN << "[" << v << "]" << RESET << " -> ";
        while (cur) {
            std::cout << "(" << BLUE << cur->to << RESET << ", " << cur->weight << ") -> ";
            cur = cur->next;
        }
        std::cout << "NULL\n";
    }
}

} // namespace ds
