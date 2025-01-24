#include <iostream>

template <size_t r, size_t c>
void PrintSpiral(int (&arr)[r][c])
{
    int rTop = 0;
    int cRight = c-1;
    int rBottom = r-1;
    int cLeft = 0;
    while (rTop <= rBottom && cLeft <= cRight)
    {
        for (int j = cLeft; j <= cRight; j++)
            std::cout << arr[rTop][j] << " ";
        for (int l = rTop + 1; l <= rBottom; l++)
            std::cout << arr[l][cRight] << " ";
        for (int k = cRight - 1; k >= cLeft; k--)
            std::cout << arr[rBottom][k] << " ";
        for (int m = rBottom - 1; m > rTop; m--)
            std::cout << arr[m][cLeft] << " ";

        rTop++;
        --cRight;
        --rBottom;
        cLeft++;
    }
}

int main()
{
    int matrix[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}};
    // Print the rotated matrix
    std::cout << "The rotated matrix is:" << std::endl;
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    PrintSpiral(matrix);

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
