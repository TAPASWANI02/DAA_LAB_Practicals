
#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n) {

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n-i-1; j++) {

            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }

        }
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

    BubbleSort(arr, n);

    cout << "\nSorted Array: ";
    printArray(arr, n);

    return 0;
}
