#include <iostream>
using namespace std;

// Function to find missing number in sorted array
int findMissingNumber(int arr[], int size) {
    int left = 0, right = size - 1;
    int start = arr[0]; // assuming sequence starts at arr[0]

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == start + mid) {
            // Missing number is in right half
            left = mid + 1;
        } else {
            // Missing number is in left half
            right = mid - 1;
        }
    }

    // 'left' is the index where the missing number should be
    return start + left;
}

int main() {
    int size;
    cout << "Enter size of the array (number of elements present): ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " sorted elements with one missing number in the sequence:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int missing = findMissingNumber(arr, size);
    cout << "Missing number is: " << missing << endl;

    return 0;
}

