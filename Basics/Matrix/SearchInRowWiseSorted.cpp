#include <iostream>

template <size_t r, size_t c>
bool Search(int (&mat)[r][c], int x)
{
    int i = 0;
    int j = c - 1;
    while (i <= r - 1 && j >= 0)
    {
        if (x < mat[i][j])
            --j;
        else if (x > mat[i][j])
            ++i;
        else
            return true;
    }
    return false;
}

int main()
{
    int matrix[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};

    // Print the rotated matrix
    std::cout << "The rotated matrix is:" << std::endl;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    Search(matrix, 32);
    return 0;
}
