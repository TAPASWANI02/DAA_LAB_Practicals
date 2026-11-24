
#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n) {

    for(int i = 1; i < n; i++) {

        int cur = arr[i];
        int prev = i - 1;

        while(prev >= 0 && arr[prev] > cur) {

            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = cur;
    }
}

void printArray(int arr[], int n) {

    for(int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
}

int main() {

    int n = 5;
    int arr[5];

    cout << "Enter 5 elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    InsertionSort(arr, n);

    cout << "\nSorted Array: ";
    printArray(arr, n);

    return 0;
}
