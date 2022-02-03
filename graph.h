#pragma once
#include <vector>
using namespace std;

class graph
{
private:
    vector<vector<int>> G;
    int n;
public:
    graph(int _n);
    void setToRandomGraphV1(double p);
    void setToRandomGraphV2();
    void addRingGraph(int size);
    int getN();
    bool checkIfExistNeighbor(int vertex);
    int calAvgDegree() const;
    int howMuchNeighbors(int vertex) const;
    void addEdge(int i, int j);
    void printGraph();
    vector<int> getNeighbors(int vertx);
};

