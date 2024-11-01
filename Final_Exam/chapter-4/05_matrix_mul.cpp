

#include<iostream>
using namespace std;

int main() {
    int row1, col1, row2, col2;

    // Input rows and columns for both matrices
    cout << "Enter rows and columns for first matrix: ";
    cin >> row1 >> col1;

    cout << "Enter rows and columns for second matrix: ";
    cin >> row2 >> col2;

    // Check if multiplication is possible
    if (col1 != row2) {
        cout << "Matrix multiplication not possible with these dimensions." << endl;
        return 0;
    }

    // Declare matrices
    int matrix1[row1][col1];
    int matrix2[row2][col2];
    int ans[row1][col2];

    // Initialize the ans matrix to 0
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            ans[i][j] = 0;
        }
    }

    // Input elements for the first matrix
    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> matrix1[i][j];
        }
    }

    // Input elements for the second matrix
    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            cin >> matrix2[i][j];
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                ans[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Output the result matrix
    cout << "Resultant matrix after multiplication:" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}

/*

3 2 

2 3 

1 2
3 4
5 6

7 8 9
10 11 12

*/