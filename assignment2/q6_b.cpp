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

    SparseMatrix addMatrices(const SparseMatrix &B) {
        if (rows != B.rows || cols != B.cols) {
            cout << "Matrix dimensions do not match.\n";
            return SparseMatrix(0, 0);
        }

        SparseMatrix result(rows, cols);

        int i = 0, j = 0;
        while (i < (int)data.size() && j < (int)B.data.size()) {
            int posA = data[i].row * cols + data[i].col;
            int posB = B.data[j].row * cols + B.data[j].col;

            if (posA < posB) {
                result.add(data[i].row, data[i].col, data[i].val);
                i++;
            } else if (posA > posB) {
                result.add(B.data[j].row, B.data[j].col, B.data[j].val);
                j++;
            } else {
                int summed = data[i].val + B.data[j].val;
                if (summed != 0) {
                    result.add(data[i].row, data[i].col, summed);
                }
                i++; j++;
            }
        }
        while (i < (int)data.size()) {
            result.add(data[i].row, data[i].col, data[i].val);
            i++;
        }
        while (j < (int)B.data.size()) {
            result.add(B.data[j].row, B.data[j].col, B.data[j].val);
            j++;
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
    SparseMatrix A(3, 3);
    A.add(0, 0, 1);
    A.add(0, 2, 2);
    A.add(1, 1, 3);

    SparseMatrix B(3, 3);
    B.add(0, 1, 4);
    B.add(1, 1, 5);
    B.add(2, 0, 6);

    cout << "Matrix A:\n";
    A.display();

    cout << "\nMatrix B:\n";
    B.display();

    SparseMatrix C = A.addMatrices(B);
    cout << "\nSum of A and B:\n";
    C.display();

    return 0;
}
