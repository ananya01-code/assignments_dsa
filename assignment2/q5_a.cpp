#include <iostream>
using namespace std;

class DiagonalMatrix {
    int* arr;
    int n;

public:
    DiagonalMatrix(int size) {
        n = size;
        arr = new int[n];
    }

    ~DiagonalMatrix() {
        delete[] arr;
    }

    void set(int i, int j, int value) {
        if (i == j)
            arr[i - 1] = value;
    }

    int get(int i, int j) {
        if (i == j)
            return arr[i - 1];
        return 0;
    }
};

int main() {
    DiagonalMatrix dm(3);
    dm.set(1, 1, 5);
    dm.set(2, 2, 8);
    dm.set(3, 3, 10);

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cout << dm.get(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}
