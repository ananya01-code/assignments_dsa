#include <iostream>
#include <vector>
using namespace std;

struct Triplet {
    int row, col, val;
};

class SparseMatrix {
    int rows, cols;
    vector<Triplet> data;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void add(int r, int c, int v) {
        if (v != 0) data.push_back({r, c, v});
    }

    SparseMatrix transpose() {
        SparseMatrix T(cols, rows);
        for (auto &t : data) {
            T.add(t.col, t.row, t.val);
        }
        return T;
    }

    void display() {
        cout << "Row Col Val\n";
        for (auto &t : data) {
            cout << t.row << "   " << t.col << "   " << t.val << "\n";
        }
    }
};

int main() {
    SparseMatrix A(3, 3);
    A.add(0, 1, 5);
    A.add(1, 0, 3);
    A.add(2, 2, 7);

    cout << "Original matrix:\n";
    A.display();

    SparseMatrix At = A.transpose();
    cout << "\nTranspose matrix:\n";
    At.display();

    return 0;
}
