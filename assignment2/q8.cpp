#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_set<int> distinctElements;
    for (int i = 0; i < n; i++)
        distinctElements.insert(arr[i]);

    cout << "Total number of distinct elements: " << distinctElements.size() << "\n";

    delete[] arr;
    return 0;
}
