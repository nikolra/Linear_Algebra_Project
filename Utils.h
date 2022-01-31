#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Utils
{
public:
    static double calDistance(vector<double> lastD, vector<double> currD);
    static void printDoubleVector(vector<double> vector);
    static vector<double> pageRank(Gragh& G, double epsilon, double N, double t);
    static vector<double> pageRank(RandomGragh& G, double epsilon, double N, double t);
    static vector<double> spcPageRank(RandomGragh& G, double epsilon, double N);
    static vector<double> spcPageRank(RandomGraghV2& G, double epsilon, double N);
};

