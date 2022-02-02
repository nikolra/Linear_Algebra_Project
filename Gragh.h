#pragma once
#include <vector>
using namespace std;

class Gragh
{
private:
    vector<vector<int>> G;
    int n;
public:
    Gragh(int _n);
    void setToRandomGraghV1(double p);
    void setToRandomGraghV2();
    void addRingGragh(int size);
    int getN();
    bool checkIfExistNeighbor(int vertex);
    int calAvgDegree() const;
    int howMuchNeighbors(int vertex) const;
    void addEdge(int i, int j);
    void printGragh();
    vector<int> getNeighbors(int vertx);
};

