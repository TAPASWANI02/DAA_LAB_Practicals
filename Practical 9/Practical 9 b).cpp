
#include <iostream>
using namespace std;

int main()
{
    int n, i, count = 0;
    int buildings[8];

    cout << "Enter number of buildings (max 8): ";
    cin >> n;

    cout << "Enter heights of " << n << " buildings:" << endl;

    for (i = 0; i < n; i++)
    {
        cout << "Height of building " << i + 1 << ": ";
        cin >> buildings[i];
    }

    int maxHeight = 0;

    for (i = 0; i < n; i++)
    {
        if (buildings[i] > maxHeight)
        {
            count++;
            maxHeight = buildings[i];
        }
    }

    cout << "Number of buildings receiving sunlight: " << count << endl;

    cout << "Height of the tallest building receiving sunlight: "
         << maxHeight << endl;

    return 0;
}

