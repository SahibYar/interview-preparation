//
// Created by Sahib Yar on 10/7/17.
//


/*
 * Write a C++ function printArray(A, m, n) that prints an m × n two-
 * dimensional array A of integers, declared to be “int** A,” to the standard
 * output. Each of the m rows should appear on a separate line.
 */


#include <iostream>
using namespace std;

void printArray(int **A, const int& m, const int& n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int m = 10;
    const int n = 10;

    int **A = new int *[m];
    for (int i = 0; i < m; i++) {
        A[i] = new int[n];
    }
    printArray(A,m,n);

    for (int i = 0; i < m; i++) {
        delete[]  A[i];
    }
    delete[] A;
    return EXIT_SUCCESS;
}
