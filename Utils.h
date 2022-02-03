#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Utils
{
public:
    static double calDistance(vector<double> lastD, vector<double> currD);
    static double calDistancePer(vector<double> lastD, vector<double> currD);
    static double calAvgVector(vector<double> d);
    static void printVector(vector<double> vector);
    static vector<double> pageRank(graph& G, double epsilon, double N, double t);
    static vector<double> spcPageRank(graph& G, double epsilon, double N);
};

