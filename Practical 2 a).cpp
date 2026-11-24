
#include <iostream>
using namespace std;

int main()
{
    // Linear Search

    int n = 5;
    int arr[5];
    int target;

    cout << "Enter 5 elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target element: ";
    cin >> target;

    int count = -1;

    for(int i = 0; i < n; i++) {

        if(arr[i] == target) {
            cout << "Element found at index " << i;
            count = i;
            break;
        }
    }

    if(count == -1) {
        cout << "Element not found";
    }

    return 0;
}
