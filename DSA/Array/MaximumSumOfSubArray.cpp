#include <iostream>

int MaxSumOfSubArray(int* arr, int size)
{
    int maxSum = 0;
    for (size_t i = 0; i < size; i++)
    {
        maxSum = std::max(maxSum + arr[i], arr[i]);
    }
    return maxSum;
}

int main()
{
    int arr[] = {-3,8,-2,4,-5,6};
    int size = sizeof(arr) / sizeof(int);
    std::cout << "The sum of sub arrays are : " << MaxSumOfSubArray(arr, size) << std::endl;
}