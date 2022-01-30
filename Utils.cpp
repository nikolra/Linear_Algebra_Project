#include <math.h>
#include "Utils.h"

using namespace std;

/********************************************************************************/
double Utils::calDistance(vector<double> lastD, vector<double> currD)
{
    double sum = 0;
    for (int i = 0; i < lastD.size(); i++)
        sum += pow((currD[i] - lastD[i]), 2);

    // and we will return the squere of the sum
    return sqrt(sum);
}
/********************************************************************************/
void Utils::printDoubleVector(vector<double> vector)
{
    cout << "(";
    for (int i = 0; i < vector.size(); i++)
    {
        if (i == (vector.size() - 1))
            cout << vector[i] << ")" << endl;
        else
            cout << vector[i] << ", ";
    }
}
/********************************************************************************/
void Utils::printIntVector(vector<int> vector)
{
    cout << "(";
    for (int i = 0; i < vector.size(); i++)
    {
        if (i == (vector.size() - 1))
            cout << vector[i] << ")" << endl;
        else
            cout << vector[i] << ", ";
    }
}
/********************************************************************************/