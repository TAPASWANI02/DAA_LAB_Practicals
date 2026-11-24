
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    int coins[n];

    cout << "Enter the coin values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter the amount: ";
    cin >> amount;

    int dp[amount + 1];
    int selected[amount + 1];

    dp[0] = 0;
    selected[0] = -1;

    for (int i = 1; i <= amount; i++)
    {
        dp[i] = INT_MAX;
        selected[i] = -1;
    }

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                int result = dp[i - coins[j]] + 1;

                if (result < dp[i])
                {
                    dp[i] = result;
                    selected[i] = coins[j];
                }
            }
        }
    }

    if (dp[amount] == INT_MAX)
    {
        cout << "Change cannot be made for the given amount.\n";
    }
    else
    {
        cout << "\nMinimum number of coins required = " << dp[amount] << endl;

        cout << "Coins selected: ";

        int current = amount;

        while (current > 0)
        {
            cout << selected[current] << " ";
            current = current - selected[current];
        }

        cout << endl;
    }

    return 0;
}
