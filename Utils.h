#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Utils
{
public:
    static double calDistance(vector<double> lastD, vector<double> currD);
    static void printDoubleVector(vector<double> vector);
    static void printIntVector(vector<int> vector);
};

