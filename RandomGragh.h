#pragma once
#include <vector>
using namespace std;

class RandomGragh
{
private:
    vector<vector<int>> RG;
    int n;
    double p;
public:
    RandomGragh(int _n, double _p);

    int getN() const;
    double getP() const;
    vector<int> getNeighbors(int vertex) const;

    void addEdge(int i, int j);
    void removeEdge(int i, int j);

    int calAvgDegree() const;
    int howMuchNeighbors(int vertex) const;

    bool checkIfExistNeighbor(int vertex) const;
    void printGragh() const;
};

