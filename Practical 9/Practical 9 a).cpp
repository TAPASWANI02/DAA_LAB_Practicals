
#include <iostream>
using namespace std;

int main()
{
    int cost[10][10], visited[10] = {0};
    int n, i, j, edges = 0;
    int min, a = 0, b = 0, total = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost adjacency matrix (0 for no edge):" << endl;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (cost[i][j] == 0)
                cost[i][j] = 9999;
        }
    }

    visited[0] = 1;

    cout << "\nEdges in Minimum Spanning Tree:" << endl;

    while (edges < n - 1)
    {
        min = 9999;

        for (i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (j = 0; j < n; j++)
                {
                    if (visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (min == 9999)
        {
            cout << "Graph is not connected." << endl;
            return 0;
        }

        cout << a << " - " << b << " : " << min << endl;

        total = total + min;
        visited[b] = 1;
        edges++;
    }

    cout << "Minimum cost = " << total << endl;

    return 0;
}
