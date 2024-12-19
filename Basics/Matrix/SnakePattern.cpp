#include <iostream>

void PrintValuesInSnakePattern(int **arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        if (i % 2 == 0)
            for (int j = 0; j < c; j++)
                std::cout << arr[i][j] << " ";
        else
            for (int j = c - 1; j >= 0; j--)
                std::cout << arr[i][j] << " ";
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
    PrintValuesInSnakePattern(arr, 3, 4);
}