#include "RandomHumpGragh.h"
#include <iostream>
#include <math.h>

using namespace std;

/********************************************************************************/
RandomHumpGragh::RandomHumpGragh(int _n, double _p) : RHG(_n, vector<int>(_n, 0)), n(_n + pow(2, 6)), p(_p)
{
    // init rand
    srand( (unsigned)time( NULL ) );

   // first we will create random gragh in the vertexes (0, ... , 2^10 - 1)
    for (int i = 0; i < _n; i++)
    {
        for (int j = 0; j < _n; j++)
        {
            // if the draw result is p -> add the edge (i, j) to the gragh
            if (((float)rand()/RAND_MAX) <= _p)
                addEdge(i, j);
        }
    }

    // now we will create the ring gragh with the rest of the vertexes (2^10,...
    for (int i = _n; i < (_n + pow(2, 6)); i++)
    {
        if (i == (_n + pow(2, 6) - 1))
            addEdge(i, _n);
        else
            addEdge(i, i + 1);
    }

    // connect the random gragh to the ring gragh
    addEdge(0, _n);
}
/********************************************************************************/
int RandomHumpGragh::getN() const
{
    return n;
}
/********************************************************************************/
double RandomHumpGragh::getP() const
{
    return p;
}
/********************************************************************************/
void RandomHumpGragh::addEdge(int i, int j)
{
    RHG[i][j] = 1;
}
/********************************************************************************/
void RandomHumpGragh::removeEdge(int i, int j)
{
    RHG[i][j] = 0;
}
/********************************************************************************/
void RandomHumpGragh::printGragh() const
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << RHG[i][j] << " ";
        }
        cout << endl;
    }
}
/********************************************************************************/
bool RandomHumpGragh::checkIfExistNeighbor(int vertex) const
{
    for (int i = 0; i < n; i++)
    {
        if (RHG[vertex][i] == 1)
            return true;
    }
    return false;
}
/********************************************************************************/
vector<int> RandomHumpGragh::getNeighbors(int vertex) const
{
    vector<int> neighbors;

    for (int i = 0; i < n; i++)
    {
        if (RHG[vertex][i] == 1)
            neighbors.push_back(i);
    }

    return neighbors;
}
/********************************************************************************/
int RandomHumpGragh::calAvgDegree() const
{
    int sum = 0;

    // go throw every vertex calculate his degree
    for (int i = 0; i < n; i++)
        sum += howMuchNeighbors(i);

    // devide sum by n to find the averge
    return (sum / n);
}
/********************************************************************************/
int RandomHumpGragh::howMuchNeighbors(int vertex) const
{
    int res = 0;
    for (int i = 0; i < n ; i++)
        res += RHG[vertex][i];

    for (int i = 0; i < n; i++)
        res += RHG[i][vertex];

    if (RHG[vertex][vertex] == 1)
        res--;

    return res;
}
/********************************************************************************/
