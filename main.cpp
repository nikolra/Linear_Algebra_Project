#include <iostream>
#include <math.h>
#include "graph.cpp"
#include "Utils.cpp"

using namespace std;

int main()
{
    double p = 0.015625;
    graph g(1024);
    g.setToRandomGraphV1(p);
    g.addRingGraph(64);
    double N = 64;
    double e = 0;
    vector<double> d = Utils::spcPageRank(g, e, N);
    Utils::printVector(d);

}
