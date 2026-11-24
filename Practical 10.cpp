
#include <iostream>
using namespace std;

int main()
{
    int cost[10][10], parent[10];
    int n, i, j, a, b, min;
    int edges = 0, total = 0;

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

        parent[i] = i;
    }

    cout << "\nEdges in Minimum Spanning Tree:" << endl;

    while (edges < n - 1)
    {
        min = 9999;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (min == 9999)
            break;

        i = a;
        while (parent[i] != i)
            i = parent[i];

        j = b;
        while (parent[j] != j)
            j = parent[j];

        if (i != j)
        {
            cout << a << " - " << b << " : " << min << endl;

            total += min;
            parent[j] = i;
            edges++;
        }

        cost[a][b] = 9999;
        cost[b][a] = 9999;
    }

    if (edges == n - 1)
        cout << "Minimum cost = " << total << endl;
    else
        cout << "Graph is not connected." << endl;

    return 0;
}
