#include <iostream>
#include<cmath>

void PrintSubSetSum(int* arr, int size, int sum, int index)
{
    if (index == size)
    {
        std::cout << sum << ", ";
        return;
    }
    PrintSubSetSum(arr, size, sum, index + 1);
    PrintSubSetSum(arr, size, sum + arr[index], index + 1);
}

int main()
{
    int arr[3] = { 1, 2, 3};
    std::cout << "{ ";
    PrintSubSetSum(arr, 3, 0, 0);
    std::cout << " }";

    std::cout << std::endl;

    int temp = 0;
    std::cout << "Enter the no " << std::endl;
    std::cin >> temp;

    return 0;
}

// 3 a, b, c
//
// 2 a, c, b
// 