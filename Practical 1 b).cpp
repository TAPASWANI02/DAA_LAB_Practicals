
#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n) {

    for(int i = 0; i < n-1; i++) {

        int SI = i;

        for(int j = i+1; j < n; j++) {

            if(arr[j] < arr[SI]) {
                SI = j;
            }
        }

        swap(arr[i], arr[SI]);
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

    SelectionSort(arr, n);

    cout << "\nSorted Array: ";
    printArray(arr, n);

    return 0;
}
