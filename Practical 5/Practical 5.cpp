
#include <iostream>
using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[n], profit[n];

    cout << "\nEnter weights of items:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Weight of Item " << i + 1 << " = ";
        cin >> weight[i];
    }

    cout << "\nEnter profits of items:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Profit of Item " << i + 1 << " = ";
        cin >> profit[i];
    }

    cout << "\nEnter knapsack capacity = ";
    cin >> capacity;

    int zk[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                zk[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                zk[i][w] = max(
                    profit[i - 1] + zk[i - 1][w - weight[i - 1]],
                    zk[i - 1][w]
                );
            }
            else
            {
                zk[i][w] = zk[i - 1][w];
            }
        }
    }

    cout << "\nMaximum Profit = " << zk[n][capacity] << endl;

    int w = capacity;

    cout << "Selected Items:\n";

    for (int i = n; i > 0; i--)
    {
        if (zk[i][w] != zk[i - 1][w])
        {
            cout << "Item " << i
                 << " (Weight = " << weight[i - 1]
                 << ", Profit = " << profit[i - 1] << ")\n";

            w = w - weight[i - 1];
        }
    }

    return 0;
}
