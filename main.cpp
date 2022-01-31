#include <iostream>
#include <math.h>
#include "Gragh.cpp"
#include "RandomGragh.cpp"
#include "RandomGraghV2.cpp"
#include "Utils.cpp"

using namespace std;

int main()
{
    RandomGraghV2 G(1024);
    G.addRingGragh(64);

    vector<double> d = Utils::spcPageRank(G, 0, 128);

    cout << "\n\n\n\n" << endl;
    cout << "Avg of the original vertexes: ";

    double sum = 0;
    for (int i = 0; i < 1024; i++)
        sum += d[i];

    cout << sum/1024 << endl;

    cout << "Avg of the new vertexes: ";
    sum = 0;
    for (int i = 1024; i < 1088; i++)
        sum += d[i];

    cout << sum/64 << endl;
    cout << "\n\n\n\n";


    /*
    vector<int> indexes(1024 + 64);

    for (int i = 0; i < 1088; i++)
        indexes[i] = i;

    for (int i = 0; i < 1086; i++)
    {
        for (int j = 0; j < (1087 - i); j++)
        {
            if (d[j] > d[j + 1])
            {
                double temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;

                int temp2 = indexes[j];
                indexes[j] = indexes[j + 1];
                indexes[j + 1] = temp2;
            }
        }
    }

    for (int i = 0; i < 1088; i++)
    {
        cout << "Value: " << d[i] << "   Index: " << indexes[i] << endl;
    }




*/
}
