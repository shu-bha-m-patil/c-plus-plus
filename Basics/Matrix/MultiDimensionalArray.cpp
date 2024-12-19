#include <iostream>
#include <vector>

const int r = 2;
const int c = 3;

// void PrintMatrix(int arr[r][c])
// {
//     std::cout << "The value of are" << std::endl;
//     for (size_t i = 0; i < r; i++)
//     {
//         for (size_t j = 0; j < c; j++)
//         {
//             std::cout << arr[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
// }

// void PrintMatrix(int arr[][3], int r)
// {
//     std::cout << "The value of are" << std::endl;
//     for (size_t i = 0; i < r; i++)
//     {
//         for (size_t j = 0; j < 3; j++)
//         {
//             std::cout << arr[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
// }

void PrintMatrix(int** arr)
{
    std::cout << "The value of are" << std::endl;
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{   
    int* arr[r];
    for (int i = 0; i < r; i++)
    {
        arr[i] = new int[c];
        for (int i = 0; i < c; i++)
        {
            arr[r][c] = i;
        }
    }
    PrintMatrix(arr);
}