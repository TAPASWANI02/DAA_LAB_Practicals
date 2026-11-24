
#include <iostream>
using namespace std;

int m[20][20];
int s[20][20];
int p[20];

void printOrder(int i, int j)
{
    if(i == j)
    {
        cout << "A" << i;
        return;
    }

    cout << "(";

    printOrder(i, s[i][j]);
    printOrder(s[i][j] + 1, j);

    cout << ")";
}

int main()
{
    int n, i, j, k, len;
    int cost;

    cout << "Enter number of matrices: ";
    cin >> n;

    cout << "Enter dimensions: ";
    for(i = 0; i <= n; i++)
        cin >> p[i];

    for(i = 1; i <= n; i++)
        m[i][i] = 0;

    for(len = 2; len <= n; len++)
    {
        for(i = 1; i <= n - len + 1; i++)
        {
            j = i + len - 1;
            m[i][j] = 999999;

            for(k = i; k < j; k++)
            {
                cost = m[i][k] + m[k + 1][j]
                     + p[i - 1] * p[k] * p[j];

                if(cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "\nMinimum multiplication cost = " << m[1][n] << endl;

    cout << "Optimal multiplication order = ";
    printOrder(1, n);

    cout << endl;

    return 0;
}
