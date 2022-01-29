#include <Gragh.cpp>

using namespace std;

int main()
{
    Gragh G(4);
    // comment
    G.addEdge(1, 0);
    G.addEdge(0, 3);
    G.addEdge(1, 3);
    G.addEdge(1, 2);
    int n = G.getN();

    double epsilon = 0.01;
    double N = 1000;
    double t = 20000;

    vector<double> d(n, 0);

    // init round
    srand( (unsigned)time( NULL ) );

    for (int i = 0; i < t; i++)
    {
        // choose random vertex
        int currVertex = rand() % (G.getN());

        for (int j = 0; j < N; j++)
        {
            // choose (1 - epsilon) or epsilon
            bool flag = ((float) rand()/RAND_MAX) < (1 - epsilon);

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
}