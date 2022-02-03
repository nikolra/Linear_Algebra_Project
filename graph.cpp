#include <iostream>
#include "graph.h"

using namespace std;

/********************************************************************************/
graph::graph(int _n) : G(_n, vector<int>(_n, 0)), n(_n)
{
}
/********************************************************************************/
void graph::setToRandomGraphV1(double p)
{
    // init rand
    srand( (unsigned)time( NULL ) );

    // go throw all potential edges
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // if the draw result is p -> add the edge (i, j) to the gragh
            if (((float)rand()/RAND_MAX) <= p)
                addEdge(i, j);
        }
    }
}

// (i, j), 1/log2(j + 1)
/********************************************************************************/
void graph::setToRandomGraphV2()
{
    // init rand
    srand( (unsigned)time( NULL ) );

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (((float)rand() / RAND_MAX) <= (1/log2(j + 1)))
                addEdge(i, j);
        }
    }
}
/********************************************************************************/
void graph::addRingGraph(int size)
{
    vector<vector<int>> newGragh(n + size, vector<int>(n + size, 0));

    // copy the last graph part:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            newGragh[i][j] = G[i][j];
        }
    }

    // create to ring graph (in his part):
    for (int i = n; i < (n + size); i++)
    {
        if (i == (n + size - 1))
            newGragh[i][n] = 1;
        else
            newGragh[i][i + 1] = 1;
    }
    // init rand
    srand( (unsigned)time( NULL ) );

    // pick a random vertex from the original graph and connect him to some vertex in the ring gragh
    newGragh[rand() % n][n] = 1;
    // replace the old gragh to the new graph
    G = newGragh;
    // update n
    n = n + size;
}
/********************************************************************************/
int graph::calAvgDegree() const
{
    int sum = 0;

    // go throw every vertex ,calculate his degree, and sum it
    for (int i = 0; i < n; i++)
        sum += howMuchNeighbors(i);

    // divide sum by n to find the average
    return (sum / n);
}
/********************************************************************************/
int graph::howMuchNeighbors(int vertex) const
{
    int res = 0;

    // find all the edges in the form: (vertex, i)
    for (int i = 0; i < n ; i++)
        res += G[vertex][i];
    // find all the edges in the form: (i, vertex)
    for (int i = 0; i < n; i++)
        res += G[i][vertex];
    // if the edge (vertex, vertex) exist, we need to delete duplicate
    if (G[vertex][vertex] == 1)
        res--;

    return res;
}
/********************************************************************************/
void graph::printGraph()
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
void graph::addEdge(int i, int j)
{
    G[i][j] = 1;
}
/********************************************************************************/
int graph::getN()
{
    return n;
}
/********************************************************************************/
bool graph::checkIfExistNeighbor(int vertex)
{
    for (int i = 0; i < n; i++)
    {
        if (G[vertex][i] == 1)
            return true;
    }
    return false;
}
/********************************************************************************/
vector<int> graph::getNeighbors(int vertex)
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
