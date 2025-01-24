#include <iostream>

template <size_t r, size_t c>
void RotateMatrixAntiClockwiseBy90(int (&arr)[r][c])
{
    // Step 1: Transpose the matrix
    std::cout << "The transposed matrix is:" << std::endl;
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = i + 1; j < c; j++)
        { // Ensure no overwriting
            std::swap(arr[i][j], arr[j][i]);
        }
    }
}

int main()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    // Print the rotated matrix
    std::cout << "The rotated matrix is:" << std::endl;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    RotateMatrixAntiClockwiseBy90(matrix);

    // Print the rotated matrix
    std::cout << "The rotated matrix is:" << std::endl;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
