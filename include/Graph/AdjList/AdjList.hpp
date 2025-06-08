#pragma once

#include <vector>
#include <map>
#include "../IGraph.hpp"

namespace ds {

struct EdgeVertex {
    int to;
    int weight;
    EdgeVertex* next;

    EdgeVertex(int to, int weight, EdgeVertex* next = nullptr);
};

class AdjList : public IGraph {
private:
    std::map<int, EdgeVertex*> table;
    bool dir;

public:
    AdjList(bool dir = false);
    ~AdjList();

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

#include "AdjList.tpp"
