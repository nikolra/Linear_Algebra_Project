#include "RandomGragh.h"
#include <iostream>

using namespace std;

/********************************************************************************/
RandomGragh::RandomGragh(int _n, double _p) : RG(_n, vector<int>(_n, 0)), n(_n), p(_p)
{
    // init rand
    srand( (unsigned)time( NULL ) );

    // go throw all potential edges
    for (int i = 0; i < _n; i++)
    {
        for (int j = 0; j < _n; j++)
        {
            // if the draw result is p -> add the edge (i, j) to the gragh
            if (((float)rand()/RAND_MAX) <= _p)
                addEdge(i, j);
        }
    }
}
/********************************************************************************/
int RandomGragh::getN() const
{
    return n;
}
/********************************************************************************/
double RandomGragh::getP() const
{
    return p;
}
/********************************************************************************/
void RandomGragh::addEdge(int i, int j)
{
    RG[i][j] = 1;
}
/********************************************************************************/
void RandomGragh::printGragh() const
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << RG[i][j] << " ";
        }
        cout << endl;
    }
}
/********************************************************************************/
bool RandomGragh::checkIfExistNeighbor(int vertex) const
{
    for (int i = 0; i < n; i++)
    {
        if (RG[vertex][i] == 1)
            return true;
    }
    return false;
}
/********************************************************************************/
vector<int> RandomGragh::getNeighbors(int vertex) const
{
    vector<int> neighbors;

    for (int i = 0; i < n; i++)
    {
        if (RG[vertex][i] == 1)
            neighbors.push_back(i);
    }

    return neighbors;
}
/********************************************************************************/
void RandomGragh::addRingGragh(int size)
{
    vector<vector<int>> newGragh(n + size, vector<int>(n + size, 0));

    // copy the last gragh part:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            newGragh[i][j] = RG[i][j];
    }

    for (int i = n; i < (n + size); i++)
    {
        if (i == (n + size - 1))
            newGragh[i][n] = 1;
        else
            newGragh[i][i + 1] = 1;
    }
    // init rand
    srand( (unsigned)time( NULL ) );

    // pick a random vertex from the old gragh
    int vertex = rand() % n;
    // connect him to some vertex in the ring gragh
    newGragh[vertex][n] = 1;
    // replace the old gragh to the new gragh
    RG = newGragh;
    // update n
    n = n + size;
}
/********************************************************************************/
int RandomGragh::calAvgDegree() const
{
    int sum = 0;

    // go throw every vertex calculate his degree
    for (int i = 0; i < n; i++)
        sum += howMuchNeighbors(i);

    // devide sum by n to find the averge
    return (sum / n);
}
/********************************************************************************/
int RandomGragh::howMuchNeighbors(int vertex) const
{
    int res = 0;
    for (int i = 0; i < n ; i++)
        res += RG[vertex][i];

    for (int i = 0; i < n; i++)
        res += RG[i][vertex];

    if (RG[vertex][vertex] == 1)
        res--;

    return res;
}
/********************************************************************************/
