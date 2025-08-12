#include <iostream>
using namespace std;

class LowerTriangularMatrix {
    int* arr;
    int n;

public:
    LowerTriangularMatrix(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2];
    }

    ~LowerTriangularMatrix() {
        delete[] arr;
    }

    void set(int i, int j, int value) {
        if (i >= j)
            arr[(i * (i - 1)) / 2 + j - 1] = value; // row-major indexing
    }

    int get(int i, int j) {
        if (i >= j)
            return arr[(i * (i - 1)) / 2 + j - 1];
        return 0;
    }
};

int main() {
    int n = 4;
    LowerTriangularMatrix lt(n);

    // Setting values only for lower triangle (i >= j)
    lt.set(1, 1, 1);
    lt.set(2, 1, 2); lt.set(2, 2, 3);
    lt.set(3, 1, 4); lt.set(3, 2, 5); lt.set(3, 3, 6);
    lt.set(4, 1, 7); lt.set(4, 2, 8); lt.set(4, 3, 9); lt.set(4, 4, 10);

    // Printing full matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << lt.get(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}
