
#include <iostream>
using namespace std;

int main()
{
    // Binary Search

    int n = 5;
    int arr[5];
    int target;

    cout << "Enter 5 elements in sorted order: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = 0, high = n - 1;

    cout << "Enter the target element: ";
    cin >> target;

    int count = -1;

    while(low <= high) {

        int mid = (low + high) / 2;

        if(arr[mid] == target) {
            cout << "Element found at index " << mid;
            count = mid;
            break;
        }

        else if(arr[mid] < target) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    if(count == -1) {
        cout << "Element not found";
    }

    return 0;
}
