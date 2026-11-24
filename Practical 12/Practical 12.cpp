
#include <iostream>
using namespace std;

#define INF 999999

int n, cost[10][10], dp[1024][10];

int tsp(int mask, int pos)
{
    if (mask == (1 << n) - 1)
        return cost[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newCost = cost[pos][city] +
                          tsp(mask | (1 << city), city);

            if (newCost < ans)
                ans = newCost;
        }
    }

    return dp[mask][pos] = ans;
}

int main()
{
    int i, j;

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:" << endl;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    for (i = 0; i < (1 << n); i++)
    {
        for (j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << "Minimum cost: " << tsp(1, 0) << endl;

    return 0;
}
