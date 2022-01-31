#include <iostream>
#include <math.h>
#include "RandomGraghV2.h"

using namespace std;

/********************************************************************************/
RandomGraghV2::RandomGraghV2(int _n) : G(_n, vector<int>(_n, 0)), n(_n)
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
void RandomGraghV2::addRingGragh(int size)
{
    vector<vector<int>> newGragh(n + size, vector<int>(n + size, 0));

    // copy the last gragh part:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            newGragh[i][j] = G[i][j];
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
    //int vertex = rand() % n;
    int vertex = 1001;

    // connect him to some vertex in the ring gragh
    newGragh[vertex][n] = 1;
    // replace the old gragh to the new gragh
    G = newGragh;
    // update n
    n = n + size;
}
/********************************************************************************/
int RandomGraghV2::getN()
{
    return n;
}
/********************************************************************************/
bool RandomGraghV2::checkIfExistNeighbor(int vertex)
{
    for (int i = 0; i < n; i++)
    {
        if (G[vertex][i] == 1)
            return true;
    }
    return false;
}
/********************************************************************************/
void RandomGraghV2::addEdge(int i, int j)
{
    G[i][j] = 1;
}
/********************************************************************************/
void RandomGraghV2::printGragh()
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
vector<int> RandomGraghV2::getNeighbors(int vertex)
{
    vector<int> neighbors;

    for (int i = 0; i < n; i++)
    {
        if (G[vertex][i] == 1)
            neighbors.push_back(i);
    }

    return neighbors;
}
/********************************************************************************/

