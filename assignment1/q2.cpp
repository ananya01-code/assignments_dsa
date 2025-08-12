#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int& size) {
    if (size == 0) return;

    int uniqueIndex = 0;

    for (int i = 0; i < size; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueIndex; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            arr[uniqueIndex] = arr[i];
            uniqueIndex++;
        }
    }
    size = uniqueIndex;
}

int main() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size.\n";
        return 1;
    }

    int arr[size];  // variable length array (supported in many compilers; for strict C++ use fixed size or dynamic)

    cout << "Enter elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    removeDuplicates(arr, size);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
