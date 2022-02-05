#include <iostream>
#include <math.h>
#include "graph.cpp"
#include "Utils.cpp"

using namespace std;

int main()
{
   // double p = 0.015625;
   // graph g(1024);
   // g.setToRandomGraphV1(p);
   // g.addRingGraph(64);
  //  double N = 64;
  //  double e = 0;
  //  vector<double> d = Utils::spcPageRank(g, e, N);
   // Utils::printVector(d);

    //double p = 0.015625;
   // graph g(1024);
   // g.setToRandomGraphV1(p);
   // double N = 128;
    //vector<double> d = Utils::spcPageRank(g, 0, N);
    //Utils::printVector(d);


    //double p = 0.015625;
    //graph g(1024);
    //g.setToRandomGraphV1(p);
    //g.addRingGraph(64);
    //double N = 128;
    //vector<double> d = Utils::spcPageRank(g, 0, N);
    //Utils::printVector(d);

    //graph g(1024);
    //g.setToRandomGraphV2();
    //double N = 64;
    //vector<double> d = Utils::spcPageRank(g, 0, N);
    //Utils::printVector(d);

    // question 10:

    double p = 0.015625;
    graph g(1024);
    g.setToRandomGraphV1(p);
    g.addRingGraph(64);

    Utils::Question10(g);

}
