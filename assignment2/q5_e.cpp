#include <iostream>
using namespace std;

class SymmetricMatrix {
    int* arr;
    int n;

public:
    SymmetricMatrix(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; ++i)
            arr[i] = 0;
    }

    ~SymmetricMatrix() {
        delete[] arr;
    }

    void set(int i, int j, int value) {
        if (i >= j)
            arr[(i * (i - 1)) / 2 + j - 1] = value;
        else
            arr[(j * (j - 1)) / 2 + i - 1] = value;
    }

    int get(int i, int j) {
        if (i >= j)
            return arr[(i * (i - 1)) / 2 + j - 1];
        else
            return arr[(j * (j - 1)) / 2 + i - 1];
    }
};

int main() {
    int n = 4;
    SymmetricMatrix sm(n);

    // Fill the symmetric matrix
    sm.set(1, 1, 1);
    sm.set(2, 1, 2);
    sm.set(2, 2, 3);
    sm.set(3, 1, 4);
    sm.set(3, 2, 5);
    sm.set(3, 3, 6);
    sm.set(4, 1, 7);
    sm.set(4, 2, 8);
    sm.set(4, 3, 9);
    sm.set(4, 4, 10);

    // Print full matrix
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << sm.get(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
