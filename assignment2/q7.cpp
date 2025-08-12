#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted halves of arr[] and count inversions
long long mergeAndCount(vector<double>& arr, int left, int mid, int right) {
    vector<double> temp(right - left + 1);
    int i = left;      // left subarray pointer
    int j = mid + 1;   // right subarray pointer
    int k = 0;
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);  // All remaining elements in left subarray form inversions
        }
    }

    // Copy remaining elements
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // Copy back to original array
    for (int idx = 0; idx < (int)temp.size(); idx++) {
        arr[left + idx] = temp[idx];
    }

    return invCount;
}

// Recursive merge sort to count inversions
long long mergeSortAndCount(vector<double>& arr, int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += mergeSortAndCount(arr, left, mid);
        invCount += mergeSortAndCount(arr, mid + 1, right);
        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<double> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long inversionCount = mergeSortAndCount(arr, 0, n - 1);

    cout << "Number of inversions: " << inversionCount << "\n";

    return 0;
}

