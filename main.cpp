#include <iostream>
#include <math.h>
#include "Gragh.cpp"
#include "Utils.cpp"

using namespace std;

int main()
{
    int n = 4;
    double epsilon = 0.6;
    double N = 1000;
    double t = 100;
    Gragh g(4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(2,1);
    g.addEdge(2,3);

    vector<double> d = Utils::pageRank(g, epsilon, N, t);

    Utils::printVector(d);


}
