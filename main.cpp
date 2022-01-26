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
    double epsilon = 0.5, N = 10, t = 10;

    vector<double> d(n, 0);

    srand( (unsigned)time( NULL ) );

    for (int i = 0; i < t; i++)
    {
        int currVertex = rand() % (G.getN());

        for (int j = 0; j < N; j++)
        {
            bool flag = ((float) rand()/RAND_MAX) < (1 - epsilon);

            if (flag && G.checkIfExistNeighbor(currVertex)) // go to random neighbor (if no neighbors go to random verted)
            {
                vector<int> neighbors = G.getNeighbors(currVertex);
                int length = neighbors.size();

                currVertex = neighbors.at(rand() % (length));
            }
            else    // go to random vertex
            {
                currVertex = rand() % (n);
            }

        }
        d[currVertex]++;
    }

    // divide every cell in d by t
    for (int i = 0; i < n; i++)
        d[i] /= t;

    // print d
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";

    cout << endl;
}