#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); // To ignore newline after number input

    vector<string> arr(n);
    cout << "Enter strings:" << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    sort(arr.begin(), arr.end());

    cout << "Strings in alphabetical order:" << endl;
    for (const string& s : arr) {
        cout << s << endl;
    }

    return 0;
}
