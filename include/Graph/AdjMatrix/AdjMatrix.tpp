#include <iostream>
#include <iomanip>

namespace ds {

inline AdjMatrix::AdjMatrix(int n, bool dir)
    : matrix(n + 1, std::vector<int>(n + 1, INF)), v_cnt(n), e_cnt(0), dir(dir) {}

inline std::vector<int> AdjMatrix::getAdjacency(int v) const {
    if (v < 1 || v >= this->matrix.size())
        throw std::out_of_range("Node does not exist in the graph.");

    std::vector<int> adj;
    for (int i = 1; i < this->matrix[v].size(); i++)
        if (this->matrix[v][i] != INF)
            adj.push_back(i);
    return adj;
}

inline std::vector<int> AdjMatrix::getVertices() const {
    std::vector<int> vertices;
    for (int v = 1; v <= v_cnt; ++v) {
        vertices.push_back(v);
    }
    return vertices;
}

inline int AdjMatrix::getWeight(int u, int v) const {
    return this->matrix[u][v];
}

inline bool AdjMatrix::isEmpty() const {
    return this->v_cnt == 0 || this->e_cnt == 0;
}

inline void AdjMatrix::insertVertex(int v) {
    if (v + 1 <= this->matrix.size())
        return;

    this->matrix.resize(v + 1);
    for (auto& row : this->matrix)
        row.resize(v + 1, INF);

    this->v_cnt = v;
}

inline void AdjMatrix::insertEdge(int u, int v, int w) {
    if (u < 1 || v < 1 || u >= this->matrix.size() || v >= this->matrix.size())
        throw std::out_of_range("Invalid vertex index in insertEdge");

    this->matrix[u][v] = w;
    this->e_cnt++;

    if (!this->dir) {
        this->matrix[v][u] = w;
        this->e_cnt++;
    }
}

inline void AdjMatrix::setDirected(bool directed) {
    this->dir = directed;
}

inline bool AdjMatrix::isDirected() const {
    return this->dir;
}

inline void AdjMatrix::deleteVertex(int v) {
    if (v < 1 || v >= matrix.size())
        throw std::out_of_range("Invalid vertex index");

    for (int i = 1; i < this->matrix.size(); i++) {
        if (this->matrix[v][i] != INF) {
            this->matrix[v][i] = INF;
            this->e_cnt--;
        }
        if (this->matrix[i][v] != INF) {
            this->matrix[i][v] = INF;
            this->e_cnt--;
        }
    }
}

inline void AdjMatrix::deleteEdge(int u, int v) {
    if (u < 1 || v < 1 || u >= this->matrix.size() || v >= this->matrix.size())
        throw std::out_of_range("Invalid vertex index in deleteEdge");

    this->matrix[u][v] = INF;
    this->e_cnt--;
}

inline void AdjMatrix::printGraph() const {
    int n = matrix.size();
    if (n <= 1) {
        std::cout << "Graph is empty.\n";
        return;
    }

    constexpr const char* GREEN = "\033[32m";
    constexpr const char* BLUE = "\033[34m";
    constexpr const char* RESET = "\033[0m";

    constexpr int CELL_WIDTH = 3;
    constexpr int NO_EDGE_PRINT_WIDTH = CELL_WIDTH;
    constexpr const char* NO_EDGE_SYMBOL = ".";

    std::cout << "[AdjMatrix]\n";

    std::cout << "    ";
    for (int j = 1; j < n; ++j)
        std::cout << GREEN << std::setw(CELL_WIDTH) << j << RESET;
    std::cout << "\n";

    for (int i = 1; i < n; ++i) {
        std::cout << GREEN << std::setw(3) << i << RESET << ":";

        for (int j = 1; j < n; ++j) {
            int val = this->matrix[i][j];
            if (val == INF)
                std::cout << std::setw(NO_EDGE_PRINT_WIDTH) << NO_EDGE_SYMBOL;
            else
                std::cout << BLUE << std::setw(CELL_WIDTH) << val << RESET;
        }
        std::cout << "\n";
    }
}

} // namespace ds