
#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &arr, int st, int mid, int end) {

    vector<int> temp;
    int i = st, j = mid + 1;

    while(i <= mid && j <= end) {

        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }
}

void MergeSort(vector<int> &arr, int st, int end) {

    if(st < end) {

        int mid = st + (end - st) / 2;

        MergeSort(arr, st, mid);       // Left half
        MergeSort(arr, mid + 1, end);  // Right half

        Merge(arr, st, mid, end);
    }
}

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    MergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";

    for(int val : arr) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}
