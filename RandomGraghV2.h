#pragma once
#include <vector>
using namespace std;

class RandomGraghV2
{
private:
    vector<vector<int>> G;
    int n;
public:
    RandomGraghV2(int _n);
    void addRingGragh(int size);
    int getN();
    bool checkIfExistNeighbor(int vertex);
    void addEdge(int i, int j);
    void printGragh();
    vector<int> getNeighbors(int vertx);
};


