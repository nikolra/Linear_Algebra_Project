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
}/********************************************************************************/
vector<double> Utils::pageRank(Gragh& G, double epsilon, double N, double t)
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
            else
            {
                // draw a random vertex
                currVertex = rand() % G.getN();
            }
        }
        d[currVertex]++;
    }

    // divide every cell in d by t
    for (int i = 0; i < G.getN(); i++)
        d[i] /= t;

    return d;
}
/********************************************************************************/
vector<double> Utils::pageRank(RandomGragh& G, double epsilon, double N, double t)
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
            else
            {
                // draw a random vertex
                currVertex = rand() % G.getN();
            }
        }
        d[currVertex]++;
    }

    // divide every cell in d by t
    for (int i = 0; i < G.getN(); i++)
        d[i] /= t;

    return d;
}
/********************************************************************************/
vector<double> Utils::spcPageRank(RandomGragh& G, double epsilon, double N)
{
    // init rand
    srand( (unsigned)time( NULL ) );
    // init vector d, and set values to 0
    vector<double> currD(G.getN(), 0);
    vector<double> lastD(G.getN(), 0);

    int n = G.getN();
    double currT = 2;

    while (1)
    {
        for (int i = 0; i < currT; i++)
        {
            // choose random vertex
            int currVertex = rand() % n;

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
                else
                {
                    // draw a random vertex
                    currVertex = rand() % n;
                }
            }
            currD[currVertex]++;
        }

        // divide vector d values by t
        for (int i = 0; i < n; i++)
            currD[i] /= currT;

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

        // save the last vector d for the checking
        lastD = currD;

        currT *= 2;
    }

    return currD;
}
/********************************************************************************/
vector<double> Utils::spcPageRank(RandomGraghV2& G, double epsilon, double N)
{
    // init rand
    srand( (unsigned)time( NULL ) );
    // init vector d, and set values to 0
    vector<double> currD(G.getN(), 0);
    vector<double> lastD(G.getN(), 0);

    int n = G.getN();
    double currT = 2;

    while (1)
    {
        for (int i = 0; i < currT; i++)
        {
            // choose random vertex
            int currVertex = rand() % n;

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
                else
                {
                    // draw a random vertex
                    currVertex = rand() % n;
                }
            }
            currD[currVertex]++;
        }

        // divide vector d values by t
        for (int i = 0; i < n; i++)
            currD[i] /= currT;

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

        // save the last vector d for the checking
        lastD = currD;
        currT *= 2;
    }

    return currD;
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