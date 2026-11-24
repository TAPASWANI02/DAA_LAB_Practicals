
#include <iostream>
using namespace std;

int graph[10][10], visited[10];
int n;

void DFS(int current)
{
    int i;

    visited[current] = 1;
    cout << current << " ";

    for (i = 0; i < n; i++)
    {
        if (graph[current][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int i, j, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    return 0;
}
