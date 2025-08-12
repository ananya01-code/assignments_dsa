#include <iostream>
using namespace std;

class UpperTriangularMatrix {
    int* arr;
    int n;

public:
    UpperTriangularMatrix(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2];
        for (int k = 0; k < n * (n + 1) / 2; k++) arr[k] = 0; // initialize
    }

    ~UpperTriangularMatrix() {
        delete[] arr;
    }

    void set(int i, int j, int value) {
        if (i <= j)
            arr[(i - 1) * n - ((i - 2) * (i - 1)) / 2 + j - i] = value;
    }

    int get(int i, int j) {
        if (i <= j)
            return arr[(i - 1) * n - ((i - 2) * (i - 1)) / 2 + j - i];
        return 0;
    }
};

int main() {
    int n = 4;
    UpperTriangularMatrix ut(n);

    ut.set(1, 1, 1);
    ut.set(1, 2, 2);
    ut.set(1, 3, 3);
ut.set(1, 4, 4);

    ut.set(2, 2, 5);
    ut.set(2, 3, 6);
    ut.set(2, 4, 7);

    ut.set(3, 3, 8);
    ut.set(3, 4, 9);

    ut.set(4, 4, 10);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ut.get(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}