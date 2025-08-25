#include <iostream>
using namespace std;

void transposeMatrix(int matrix[][10], int transpose[][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int matrix[10][10], transpose[10][10];
    int r, c;

    cout << "Enter rows and columns of the matrix: ";
    cin >> r >> c;

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];

    transposeMatrix(matrix, transpose, r, c);

    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
