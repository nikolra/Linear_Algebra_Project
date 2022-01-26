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

    int getN();

    bool checkIfExistNeighbor(int vertex);

    void addEdge(int i, int j);
    void removeEdge(int i, int j);
    void printGragh();

    vector<int> getNeighbors(int vertx);

};

