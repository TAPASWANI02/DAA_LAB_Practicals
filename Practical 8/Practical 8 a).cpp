
#include <iostream>
using namespace std;

int graph[10][10], visited[10];
int queue[10];
int n;

void BFS(int start)
{
    int front = 0, rear = 0;
    int i, current;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        current = queue[front++];
        cout << current << " ";

        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    cout << "BFS Traversal: ";
    BFS(start);

    return 0;
}
