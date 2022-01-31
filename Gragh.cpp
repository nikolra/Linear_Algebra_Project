#include <iostream>
#include "Gragh.h"

using namespace std;

/********************************************************************************/
Gragh::Gragh(int _n) : G(_n, vector<int>(_n, 0)), n(_n)
{
}
/********************************************************************************/
void Gragh::printGragh()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}
/********************************************************************************/
void Gragh::addEdge(int i, int j)
{
    G[i][j] = 1;
}
/********************************************************************************/
int Gragh::getN()
{
    return n;
}
/********************************************************************************/
bool Gragh::checkIfExistNeighbor(int vertex)
{
    for (int i = 0; i < n; i++)
    {
        if (G[vertex][i] == 1)
            return true;
    }
    return false;
}
/********************************************************************************/
vector<int> Gragh::getNeighbors(int vertex)
{
    vector<int> neighbors;

    for (int i = 0; i < n; i++)
    {
        if (G[vertex][i] == 1)
        {
            neighbors.push_back(i);
        }
    }

    return neighbors;
}
/********************************************************************************/
