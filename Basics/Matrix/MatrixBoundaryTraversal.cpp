#include <iostream>

void PrintValuesInSnakePattern(int **arr, int r, int c)
{
    for (int j = 0; j < c; j++)
        std::cout << arr[0][j] << " ";
    for (int i = 0; i < r; i++)
        std::cout << arr[i][c - 1] << " ";
    for (int j = c - 2; j >= 0; j--)
        std::cout << arr[r - 1][j] << " ";
    for (int i = r - 2; i > 0; i--)
        std::cout << arr[i][0] << " ";
}

void PrintMatrix(int **arr, int r)
{
    std::cout << "The value of are" << std::endl;
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int *arr[3];
    for (size_t i = 0; i < 3; i++)
    {
        arr[i] = new int[4];
        for (size_t j = 0; j < 4; j++)
            arr[i][j] = j;
    }
    PrintMatrix(arr, 3);
    PrintValuesInSnakePattern(arr, 3, 4);
}