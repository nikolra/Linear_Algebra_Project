#include <iostream>
#include <math.h>
#include "Gragh.cpp"
#include "RandomGragh.cpp"
#include "Utils.cpp"

using namespace std;

int main()
{
    /******************** question 7.1 ***********************/

    RandomGragh RG(pow(2, 10), 1/pow(2, 6));
    int n = RG.getN();

    //cout << "The random gragh: " << endl;
   // RG.printGragh();

    cout << "The Avg Degree: " << endl;
    cout << RG.calAvgDegree() << endl;

    /******************** question 7.2 ***********************/
    /*
    RandomGragh RG(pow(2, 10), 1/pow(2, 6));
    int n = RG.getN();
    double epsilon = 0;

    //double N = pow(2, 6); // question 8.1
    double N = pow (2, 7); // question 8.1

    double t = 2;   // initial t

    // init rand
    srand( (unsigned)time( NULL ) );
    // init vector d, and set values to 0
    vector<double> currD(n, 0);
    vector<double> lastD(n, 0);

    while (1)
    {
        for (int i = 0; i < t; i++)
        {
            // choose random vertex
            int currVertex = rand() % RG.getN();

            for (int j = 0; j < N; j++)
            {
                // choose (1 - epsilon) or epsilon
                bool flag = ((float) rand()/RAND_MAX) <= (1 - epsilon);

                // go to random neighbor (if no neighbors go to random vertex)
                if (flag && RG.checkIfExistNeighbor(currVertex))
                {
                    vector<int> neighbors = RG.getNeighbors(currVertex);
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
            currD[i] /= t;

        // print t just for checking:
        cout << "t = " << t << " (2^" << log2(t) << ")" << endl;

        if (t != 2)
        {
            double currDistance = Utils::calDistance(lastD, currD);
            if (currDistance < (1/pow(2, 8)))
            {
                cout << "STOPED! The distance: " << currDistance << endl;
                break;
            }
            // remove this comment for question 8.2

            if (t == pow(2, 14))
            {
                cout << "STOPED! distance is not small enough." << endl;
                cout << "The distance: " << currDistance << endl;
                break;
            }

        }

        // save the last vector d for the checking
        for (int i = 0; i < n; i++)
            lastD[i] = currD[i];

        t *= 2;
    }

*/




    /*
    double epsilon = 1;
    double N = 100;
    double t = 100000;

    vector<double> d(n, 0);

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
                currVertex = rand() % n;
            }
        }
        d[currVertex]++;
    }

    // divide every cell in d by t
    for (int i = 0; i < n; i++)
    {
        d[i] /= t;
    }

    // print d
    for (int i = 0; i < n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
     */
}
