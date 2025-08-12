#include <iostream>
using namespace std;

class TriDiagonalMatrix {
    int* arr;
    int n;

public:
    TriDiagonalMatrix(int size) {
        n = size;
        arr = new int[3 * n - 2];
        for (int i = 0; i < 3 * n - 2; i++) arr[i] = 0; // initialize to zero
    }

    ~TriDiagonalMatrix() {
        delete[] arr;
    }

    void set(int i, int j, int value) {
        if (i - j == 1)              // lower diagonal
            arr[i - 2] = value;
        else if (i - j == 0)         // main diagonal
            arr[n - 1 + i - 1] = value;
        else if (i - j == -1)        // upper diagonal
            arr[2 * n - 1 + i - 1] = value;
    }

    int get(int i, int j) {
        if (i - j == 1)
            return arr[i - 2];
        else if (i - j == 0)
            return arr[n - 1 + i - 1];
        else if (i - j == -1)
            return arr[2 * n - 1 + i - 1];
        return 0;
    }
};

int main() {
    int n = 4;
    TriDiagonalMatrix tm(n);

    tm.set(1, 1, 5);
    tm.set(1, 2, 2);
    tm.set(2, 1, 3);
    tm.set(2, 2, 7);
    tm.set(2, 3, 1);
    tm.set(3, 2, 4);
    tm.set(3, 3, 9);
    tm.set(3, 4, 6);
    tm.set(4, 3, 8);
    tm.set(4, 4, 10);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << tm.get(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}
