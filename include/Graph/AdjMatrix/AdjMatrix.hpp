#pragma once

#include <vector>
#include "../IGraph.hpp"

namespace ds {

class AdjMatrix : public IGraph {
private:
    std::vector<std::vector<int>> matrix;
    int v_cnt;
    int e_cnt;
    bool dir;

public:
    AdjMatrix(int n, bool dir = false);

    std::vector<int> getAdjacency(int v) const override;
    std::vector<int> getVertices() const override;
    int getWeight(int u, int v) const override;
    bool isEmpty() const override;
    void insertVertex(int v) override;
    void insertEdge(int u, int v, int w) override;
    void setDirected(bool directed) override;
    bool isDirected() const override;
    void deleteVertex(int v) override;
    void deleteEdge(int u, int v) override;
    void printGraph() const override;
};
} // namespace ds

#include "AdjMatrix.tpp"
