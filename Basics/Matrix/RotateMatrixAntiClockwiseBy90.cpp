#include <iostream>
using namespace std;

template <size_t r, size_t c>
void RotateMatrixAntiClockwiseBy90(int (&arr)[r][c]) {
    // Step 1: Transpose the matrix
    cout << "The transposed matrix is:" << endl;
    for (size_t i = 0; i < r; i++) {
        for (size_t j = i + 1; j < c; j++) { // Ensure no overwriting
            swap(arr[i][j], arr[j][i]);
        }
    }

    // Step 2: Reverse each column
    for (size_t j = 0; j < c; j++) {
        for (size_t i = 0; i < r / 2; i++) {
            swap(arr[i][j], arr[r - i - 1][j]);
        }
    }

    // Print the rotated matrix
    cout << "The rotated matrix is:" << endl;
    for (size_t i = 0; i < r; i++) {
        for (size_t j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
// Print the rotated matrix
    cout << "The rotated matrix is:" << endl;
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    RotateMatrixAntiClockwiseBy90(matrix);

    return 0;
}
