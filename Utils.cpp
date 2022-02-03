#include <math.h>
#include "Utils.h"

using namespace std;

/********************************************************************************/
// This method calculate the distance ||currD - lastD||
double Utils::calDistance(vector<double> lastD, vector<double> currD)
{
    // Assume currD = (c1, c2, ..., cn)
    //        lastD = (l1, l2, ..., ln)
    // First we will sum for each i -> (ci - li)^2:
    double sum = 0;
    for (int i = 0; i < lastD.size(); i++)
        sum += pow((currD[i] - lastD[i]), 2);

    // And we will return the squere of the sum
    return sqrt(sum);
}
/********************************************************************************/
// for checking with eyal, can be deleted in the end
double Utils::calDistancePer(vector<double> lastD, vector<double> currD)
{
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < lastD.size(); i++)
        sum1 += pow((currD[i] - lastD[i]), 2);

    for (int i = 0; i < lastD.size(); i++)
        sum2 += pow(lastD[i], 2);

    double len1 = sqrt(sum1);
    double len2 = sqrt(sum2);

    return ((len1/len2) * 100);
}
/********************************************************************************/
// This method calculate the avg number of vector d elements
double Utils::calAvgVector(vector<double> d)
{
    double sum = 0;
    for (int i = 0; i < d.size(); i++)
        sum += d[i];

    return (sum / d.size());
}
/********************************************************************************/
vector<double> Utils::pageRank(graph& G, double epsilon, double N, double t)
{
    vector<double> d(G.getN(), 0);

    // init rand
    srand( (unsigned)time( NULL ) );

    for (int i = 0; i < t; i++)
    {
        // choose random vertex
        int currVertex = rand() % G.getN();

        for (int j = 0; j < N; j++)
        {
            // choose (1 - epsilon) or epsilon
            bool flag = ((float) rand()/RAND_MAX) <= (1 - epsilon);

            // go to random neighbor (if no neighbors go to random vertex)
            if (flag && G.checkIfExistNeighbor(currVertex))
            {
                vector<int> neighbors = G.getNeighbors(currVertex);
                currVertex = neighbors.at(rand() % (neighbors.size())); // draw a random neighbor
            }
            else    // (1 - epsilon) or no neighbors
            {
                // draw a random vertex
                currVertex = rand() % G.getN();
            }
        }
        d[currVertex]++;
    }

    // divide every cell in vector d by t
    for (int i = 0; i < G.getN(); i++)
        d[i] /= t;

    return d;
}
/********************************************************************************/
vector<double> Utils::spcPageRank(graph& G, double epsilon, double N)
{
    // init rand
    srand( (unsigned)time( NULL ) );
    // init vector currD and lastD, and set values to 0
    vector<double> currD(G.getN(), 0);
    vector<double> lastD(G.getN(), 0);
    // set t to 2 for start
    double currT = 2;

    while (true)
    {
        // Apply regular pagerank with the current t value
        currD = Utils::pageRank(G, epsilon, N, currT);

        // print t just for checking:
        cout << "t = " << currT << " (2^" << log2(currT) << ")" << endl;

        if (currT != 2)
        {
            double currDistance = Utils::calDistance(lastD, currD);
            if (currDistance < (1/pow(2, 8)))
            {
                cout << "STOPED! The distance: " << currDistance << endl;
                break;
            }
        }

        // save the last vector d for next iteration checking
        lastD = currD;
        currT *= 2;
    }

    return currD;
}
/********************************************************************************/
void Utils::printVector(vector<double> vector)
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
