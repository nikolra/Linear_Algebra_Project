#pragma once
#include <vector>

using namespace std;

class RandomHumpGragh
{
private:
    vector<vector<int>> RHG;
    int n;
    double p;
public:
    RandomHumpGragh(int _n, double _p);

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

