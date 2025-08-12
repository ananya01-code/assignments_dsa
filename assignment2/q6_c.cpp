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

    SparseMatrix multiply(const SparseMatrix &B) {
        if (cols != B.rows) {
            cout << "Matrix dimensions incompatible for multiplication.\n";
            return SparseMatrix(0, 0);
        }

        SparseMatrix result(rows, B.cols);

        // Naive multiply: For each A element, find B elements where colA == rowB
        for (auto &a : data) {
            for (auto &b : B.data) {
                if (a.col == b.row) {
                    // Accumulate result for position (a.row, b.col)
                    bool added = false;
                    for (auto &r : result.data) {
                        if (r.row == a.row && r.col == b.col) {
                            r.val += a.val * b.val;
                            added = true;
                            break;
                        }
                    }
                    if (!added) {
                        result.add(a.row, b.col, a.val * b.val);
                    }
                }
            }
        }

        return result;
    }

    void display() {
        cout << "Row Col Val\n";
        for (auto &t : data) {
            cout << t.row << "   " << t.col << "   " << t.val << "\n";
        }
    }
};

int main() {
    SparseMatrix A(2, 3);
    A.add(0, 0, 1);
    A.add(0, 2, 2);
    A.add(1, 1, 3);

    SparseMatrix B(3, 2);
    B.add(0, 1, 4);
    B.add(2, 0, 5);
    B.add(2, 1, 6);

    cout << "Matrix A:\n";
    A.display();

    cout << "\nMatrix B:\n";
    B.display();

    SparseMatrix C = A.multiply(B);
    cout << "\nProduct of A and B:\n";
    C.display();

    return 0;
}
