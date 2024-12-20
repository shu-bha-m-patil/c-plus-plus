#include <iostream>

template <size_t r, size_t c>
void SpiralTraversalOfMatrix(int (&arr)[r][c])
{
    int topLeft = 0;
    int topRight = 0;
    int bottomLeft = 0;
    int bottomRight = 0;
    for (int i = 0; i < r; i++)
    {
        i = topLeft;
        int j = topRight;
        for (j = 0; j < c; j++)
        {
            std::cout << arr[i][j] << " ";
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
